#include "../sanitizer_common/sanitizer_common.h"
#include "../sanitizer_common/sanitizer_flag_parser.h"
#include "../sanitizer_common/sanitizer_flags.h"
#include "../sanitizer_common/sanitizer_libc.h"

#include "defs.h"
#include "aibar.h"

using namespace __aibar;

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
#include <sys/mman.h>
       #include <sys/stat.h>        /* For mode constants */
       #include <fcntl.h>
#include "sanitizer_common/sanitizer_stacktrace.h"
#include "sanitizer_common/sanitizer_common.h"

using namespace std;

bool *int2kFlag = NULL;
vector<int> *e = NULL;
map<string, int> mapName;
int **mapID = NULL;
char **funcName = NULL;
int _int2k_nFunction = 0;
bool _int2k_visitedMain = false;

extern "C" SANITIZER_INTERFACE_ATTRIBUTE
void _int2k_translateName(char* name, int ID);

extern "C" SANITIZER_INTERFACE_ATTRIBUTE
void _int2k_add_edge(char *, char *);

extern "C" SANITIZER_INTERFACE_ATTRIBUTE
void _int2k_apply(char *funcName, int val);

extern "C" SANITIZER_INTERFACE_ATTRIBUTE
void _aibarFunc(char* name);

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
      //printf("deactivate %s\n", funcName[id]);
      _int2k_apply(funcName[id], 1);
    }
  } 
  printf("\n");
  return 0;
}

//extern "C" SANITIZER_INTERFACE_ATTRIBUTE
void _int2k_translateName(char* name, int ID) { 
  mapName[name] = ID;
  funcName[ID] = name;
}

//extern "C" SANITIZER_INTERFACE_ATTRIBUTE
void _int2k_add_edge(char *f1, char *f2) {
  int id1 = mapName[f1];
  int id2 = mapName[f2];
  e[id1].push_back(id2);
}

//Aibari
          #define errExit(msg)    do { perror(msg); exit(EXIT_FAILURE); \
                                   } while (0)
	
extern "C" SANITIZER_INTERFACE_ATTRIBUTE
void _aibarFunc(char* name){
  const char* header = "/data/shm/";
  char* fullName;
  fullName = (char*) malloc(strlen(name)+11);
  strcpy(fullName, header);
  strcat(fullName, name);
  char shm[70];
  if(FILE *ptr = fopen(fullName, "r")){
    if(fgets(shm,70,ptr)!=NULL){
      int fd = shm_open(shm, O_RDWR, 0); 
      if(fd==-1)errExit("shm_open");
      int *shmp = (int*) mmap(NULL, sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
      if(shmp==MAP_FAILED)errExit("mmap");
      *shmp = *shmp+1;
    }else{
      printf("u stupid \n");
    }
    fclose(ptr);
  }/*
  //ptr = fopen(header, "a");
  printf("prepare to open file\n");
  if(ptr == NULL) {
    printf("u stupid \n");
    //exit(1);
    return;
  }
  printf("open  file ok\n");
  fprintf(ptr, "%s \n", "PASS_ADDED");
  fclose(ptr);*/
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
  delete [] int2kFlag;
  for(int i = 0; i < _int2k_nFunction; ++i)
    e[i].clear();
  delete [] e;
  delete [] mapID;
  delete [] funcName;
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

extern "C" SANITIZER_INTERFACE_ATTRIBUTE
void _int2k_apply(char *funcName, int val) {
  int id = mapName[funcName];
  for(int i = 0; i < (int)e[id].size(); ++i)
  {
    int2kFlag[e[id][i]] = val;
  }
}

extern "C" SANITIZER_INTERFACE_ATTRIBUTE
void _int2k_set_flag(char *funcName, int val) {
  int id = mapName[funcName];
  int2kFlag[id] = val;
}

