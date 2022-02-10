import sys
import pydot
args = sys.argv[1:]
graphs = pydot.graph_from_dot_file(args[0])

def removeColon(s):
  if(s.find(':')!=-1):
    return s[0:s.find(':')]
  else:
    return s

def extractNode(txt):
  tmp = txt.split(' ')
  name = tmp[0]
  info = ''
  for i in range(1, len(tmp)):
    info = info + tmp[i] + ' '
  y = txt[txt.find('fun:'):]
  try:
    func = y[:y.find('\\')].split()[1]
    return [name, info, func]
  except:
    return [name, '-1', '-1']

nodes = []
edges = []

for graph in graphs:
  nodeList = graph.get_node_list()
  for node in nodeList:
    nodes += [extractNode(node.to_string())]

  subGraphs = graph.get_subgraphs()
  for subGraph in subGraphs:    
    for e in subGraph.get_edge_list():
      src = e.get_source()
      src = removeColon(src)
      dst = e.get_destination()
      dst = removeColon(dst)
      edges += [[src, dst]]
  for e in graph.get_edge_list():
    src = e.get_source()
    src = removeColon(src)
    dst = e.get_destination()
    dst = removeColon(dst)  
    edges += [[src, dst]]
print(len(nodes), len(edges))
for i in nodes:
  for j in i:
    print(j)
  print()
for i in edges:
  print(i[0], i[1])
