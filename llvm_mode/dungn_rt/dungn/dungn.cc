#include "../sanitizer_common/sanitizer_common.h"
#include "../sanitizer_common/sanitizer_flag_parser.h"
#include "../sanitizer_common/sanitizer_flags.h"
#include "../sanitizer_common/sanitizer_libc.h"

#include "defs.h"
#include "dungn.h"

using namespace __dungn;

#include "../../../runtime/include/tag_set.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <unistd.h>
#include <iostream>
#include <fcntl.h>
#include <fstream>

#include "sanitizer_common/sanitizer_stacktrace.h"
#include "sanitizer_common/sanitizer_common.h"

using namespace std;

//ICFG
bool *iInt2kFlag = NULL;
vector<int> *iE = NULL;
map<string, int> iMapName;
int **iMapID = NULL;
char **lineName = NULL;
int _int2k_nLine = 0;
vector<vector<string> > lineNumToInfo;
int maxNumberOfLine=0;

bool *int2kFlag = NULL;
vector<int> *e = NULL;
map<string, int> mapName;
int **mapID = NULL;
char **funcName = NULL;
int _int2k_nFunction = 0;
bool _int2k_visitedMain = false;

//ICFG 
extern "C" SANITIZER_INTERFACE_ATTRIBUTE
void _iInt2k_lineNumToInfo(int ln, char *name);

//ICFG
extern "C" SANITIZER_INTERFACE_ATTRIBUTE
void _iInt2k_translateName(char *name, int ID);

extern "C" SANITIZER_INTERFACE_ATTRIBUTE
void _int2k_translateName(char* name, int ID);

//ICFG
extern "C" SANITIZER_INTERFACE_ATTRIBUTE
void _iInt2k_add_edge(char *, char *);

extern "C" SANITIZER_INTERFACE_ATTRIBUTE
void _int2k_add_edge(char *, char *);

//ICFG
extern "C" SANITIZER_INTERFACE_ATTRIBUTE
void _iInt2k_apply(char *lineName, int val);

extern "C" SANITIZER_INTERFACE_ATTRIBUTE
void _int2k_apply(char *funcName, int val);

extern "C" SANITIZER_INTERFACE_ATTRIBUTE
void _aibarFunc(char* name);

//ICFG
extern "C" SANITIZER_INTERFACE_ATTRIBUTE
void _iInt2k_lineNumToLineInfo(int ln, char *name)
{
  if(ln == 0)
    return;
  while(lineNumToInfo.size() <= ln)
    lineNumToInfo.push_back({});
  lineNumToInfo[ln].push_back(name);
}

int toInt(char *s) {
  int res = 0;
  for(int i = 0; i < (int)strlen(s); ++i)
  {
    if(s[i] > '9' || s[i] < '0')
      return -1;
    res = res * 10 + s[i] - '0';
  }
  return res;
}

//ICFG
extern "C" SANITIZER_INTERFACE_ATTRIBUTE
void _iInt2k_handle_function_name(int n, char **s)
{
  for(int i = 0; i < n; ++i)
  {
    _iInt2k_translateName(s[i], i);
  }
}

extern "C" SANITIZER_INTERFACE_ATTRIBUTE
void _int2k_handle_function_name(int n, char **s)
{
  printf("Translating ... \n");
  for(int i = 0; i < n; ++i)
  {
    //printf("%s ", s[i]);
    _int2k_translateName(s[i], i);
  }
  printf("done Translating function names! \n");
}

//ICFG
extern "C" SANITIZER_INTERFACE_ATTRIBUTE 
void _iInt2k_handle_meta_data(int n, int *id, char **s1, char **s2)
{
  int k = 0;
  for(int i = 0; i < n; ++i)
  {
    for(int j = id[k]; j < id[k+1]; ++j)
    {
      _iInt2k_add_edge(s1[i], s2[j]);
    }
  }
}

extern "C" SANITIZER_INTERFACE_ATTRIBUTE
void _int2k_handle_meta_data(int n, int *id, char **s1, char **s2)
{
  printf("connecting the unrelated function...\n");
  int k = 0;
  for(int i = 0; i < n; ++i)
  {
    for(int j = id[k]; j < id[k+1]; ++j)
    {
      _int2k_add_edge(s1[i], s2[j]); 
    }
  }
  printf("done connecting the metadata! \n");
}

extern "C" SANITIZER_INTERFACE_ATTRIBUTE
int _int2k_handle_arg(int argc, char **argv) { 
  fd_set readfds;
  FD_ZERO(&readfds);
  FD_SET(STDIN_FILENO, &readfds);
  fd_set savefds = readfds;

  struct timeval timeout;
  timeout.tv_sec = 0;
  timeout.tv_usec = 0;
  int sel_rv = select(1, &readfds, NULL, NULL, &timeout);
  if(sel_rv > 0) 
  {
    ofstream out; out.open("_int2k_STDIN.txt");
    string s = "";
    char buf[2];
    while(fgets(buf, 2, stdin))
    {
      out << buf;
    }
    out.close();
    ifstream inp; inp.open("_int2k_STDIN.txt");
    while(inp >> s)
    {
      //cout << s << "\n";
      int id = -1;
      if(mapName.find(s) == mapName.end())
      {
        cout << "can't find " << s << "\n";
      } else {
        id = mapName[s];
      }
      if(id != -1 && id < _int2k_nFunction) {
        int2kFlag[id] = 1;
        printf("deactivate %s\n", funcName[id]);
      }
    }
    inp.close();
    int file = open("_int2k_STDIN.txt", O_RDONLY);
    dup2(file, 0);
  }
  for(int i = 1; i < argc; ++i)
  {
    char *s = argv[i];
    int id = -1;
    if(mapName.find(s) == mapName.end())
    {
      id = toInt(s);
      if(id == -1) {
        printf("can't find %s\n",s);
      }
    } else {
      id = mapName[s];
    }
    if(id != -1 && id < _int2k_nFunction) {
      //int2kFlag[id] = 1;
      _int2k_apply(funcName[id], 1);
    }
    string tmp = argv[i];
    if(tmp[0] == ':')
    {
      int ln = 0, j = 1;
      while (j < tmp.length() && tmp[j] >= '0' && tmp[j] <= '9') {
        ln = ln * 10 + (tmp[j] - '0');
        j++;
      }
      if(ln > 0 && ln < lineNumToInfo.size())
      {
        for(int k = 0; k < lineNumToInfo[ln].size(); ++k)
        {
          char *cstr = new char[lineNumToInfo[ln][k].length() + 1];
          strncpy(cstr, lineNumToInfo[ln][k].c_str(), lineNumToInfo[ln][k].length() + 1);
          _iInt2k_apply(cstr, 1);
        }
      }
    }
  } 
  printf("\n");
  return 0;
}

//ICFG
void _iInt2k_translateName(char *name, int ID) {
  iMapName[name] = ID;
  lineName[ID] = name;
}

//extern "C" SANITIZER_INTERFACE_ATTRIBUTE
void _int2k_translateName(char* name, int ID) { 
  mapName[name] = ID;
  funcName[ID] = name;
}

// ICFG
void _iInt2k_add_edge(char *l1, char *l2) {
  int id1 = iMapName[l1];
  int id2 = iMapName[l2];
  iE[id1].push_back(id2);
}

//extern "C" SANITIZER_INTERFACE_ATTRIBUTE
void _int2k_add_edge(char *f1, char *f2) {
  int id1 = mapName[f1];
  int id2 = mapName[f2];
  e[id1].push_back(id2);
}

//Aibar
extern "C" SANITIZER_INTERFACE_ATTRIBUTE
void _aibarFunc(char* name){
  FILE * ptr;
  const char* header = "/data/pass/";
  char* fullName;
  fullName = (char*) malloc(strlen(name)+12);
  strcpy(fullName, header);
  strcat(fullName, name);
  ptr = fopen(fullName, "a");
  //ptr = fopen(header, "a");
  printf("prepare to open file\n");
  if(ptr == NULL) {
    printf("u stupid \n");
    //exit(1);
    return;
  }
  printf("open file ok\n");
  fprintf(ptr, "%s \n", "PASS_ADDED");
  fclose(ptr);
}

// ICFG
extern "C" SANITIZER_INTERFACE_ATTRIBUTE
void _iInt2k_init_flag(int len) {
  _int2k_visitedMain = true;
  iInt2kFlag = new bool[len];
  iMapID = new int*[len];
  lineName = new char*[len];
  for(int i = 0; i < len; ++i)
    iInt2kFlag[i] = 0;
  iE = new vector<int>[len];
  _int2k_nLine = len;
}

extern "C" SANITIZER_INTERFACE_ATTRIBUTE
void _int2k_init_flag(int len) {
  _int2k_visitedMain = true;
  int2kFlag = new bool[len];
  mapID = new int*[len];
  funcName = new char*[len];
  for(int i = 0; i < len; ++i)
    int2kFlag[i] = 0;
  e = new vector<int>[len];
  _int2k_nFunction = len;
}

extern "C" SANITIZER_INTERFACE_ATTRIBUTE
void _int2k_delete_flag() {
  delete [] iInt2kFlag;
  delete [] int2kFlag;
  for(int i = 0; i < _int2k_nFunction; ++i)
    e[i].clear();
  delete [] e;
  delete [] mapID;
  delete [] funcName;
}

// ICFG
extern "C" SANITIZER_INTERFACE_ATTRIBUTE
void _iInt2k_check(char *line) {
  if(!_int2k_visitedMain)
    return;
  int id = iMapName[line];
  if(iInt2kFlag[id] == 0)
    return;
  else
    exit(0);
}

extern "C" SANITIZER_INTERFACE_ATTRIBUTE
void _int2k_check(char *funcName) {
  if(!_int2k_visitedMain)
    return;
  int id = mapName[funcName];
  if(int2kFlag[id] == 0)
    return;
  else
    exit(0);
}

//ICFG
extern "C" SANITIZER_INTERFACE_ATTRIBUTE
void _iInt2k_apply(char *lineName, int val) {
  int id = iMapName[lineName];
  for(int i = 0; i < (int)e[id].size(); ++i) 
  {
    iInt2kFlag[id] == val;
  }
}

extern "C" SANITIZER_INTERFACE_ATTRIBUTE
void _int2k_apply(char *funcName, int val) {
  int id = mapName[funcName];
  for(int i = 0; i < (int)e[id].size(); ++i)
  {
    int2kFlag[e[id][i]] = val;
  }
}

//ICFG
extern "C" SANITIZER_INTERFACE_ATTRIBUTE
void _iInt2k_set_flag(char *line, int val) {
  int id = iMapName[line];
  iInt2kFlag[id] = val;
}

extern "C" SANITIZER_INTERFACE_ATTRIBUTE
void _int2k_set_flag(char *funcName, int val) {
  int id = mapName[funcName];
  int2kFlag[id] = val;
}

