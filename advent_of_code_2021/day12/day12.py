from copy import deepcopy as dp
from copy import copy as cp

# Today is a graph search problem
def dfs(graph, currentPath, paths, s):
    if s.islower():
        graph.get(s)[0]=True #blacken small nodes (this is start and end as well)
    
    currentPath.append(s)

    if s == "end":
        paths.append(dp(currentPath)) # I really hate python semantics sometimes
        return paths
    
    #  print("current s:",s)
    # recurse on neighbors
    for n in graph.get(s)[1]:
        if graph.get(n)[0] is False: # if not blackened previously explore it
            paths = dfs(dp(graph),dp(currentPath),paths,n)
    return paths

def p1(f):
    # this feels like DFS
    # 1. If we are at a small node blacken it
    # 2. Explore all neighbors
    # 3. If we are at END then append path to list and return (continue recursing on unexplored neighbors)
    # 4. Once all neighbors of large nodes have been blackened we are done (return to parent and explore next)

    # want to pass graph state down but not propagate back so we can explore all paths from each node.

    # first we need to make our graph
    # we can use a dict to represent our adjacency list
    # the node name will be a key
    # the val will be a list containing a bool (the color b/w) and a list (the adj list)
    graph = {}
    for line in f.readlines():
        n1,n2 = line.strip('\n').split("-")
        if graph.get(n1): # we just need to add the edge
            graph.get(n1)[1].append(n2)
        else: # need to add node and edge
            graph.update({n1:[False,[n2]]})

        if graph.get(n2): # we just need to add the edge
            graph.get(n2)[1].append(n1)
        else: # need to add node and edge
            graph.update({n2:[False,[n1]]})
    
    #  for key in graph.keys():
        #  print(key,graph.get(key)[1])
    # now find all paths
    paths = dfs(graph,[],[],"start")
    for path in paths:
        print(path)
    
    print("number of paths through visiting small caves once:",len(paths))


def dfsSmallTwice(graph, currentPath, paths, s, switch):
    if s.islower():
        if s in currentPath:
            switch = 1
        graph.get(s)[0]=True #blacken small nodes that appear twice

    print("switch after if:",switch)

    currentPath.append(s)

    if s == "end":
        paths.append(dp(currentPath)) # I really hate python semantics sometimes
        return paths
    
    # recurse on neighbors
    for n in graph.get(s)[1]:
        #  print("current s:",s)
        if graph.get(n)[0] is False or not switch: # if not blackened previously explore it
            paths = dfsSmallTwice(dp(graph),dp(currentPath),paths,n,switch)
    return paths

def p2(f):
    # simplest way to accomodate part 2 is just add a switch that is on if we have already selected somthing small twice. 
    # then we can say if the switch is off we can explore black nodes. This must exclude the start node however.
    # if we want to exclude start but not add any extra checks we can just remove the edge from anything to start effectively making
    # start a directed node in a undirected graph but oh well

    graph = {}
    for line in f.readlines():
        n1,n2 = line.strip('\n').split("-")
        if graph.get(n1): # we just need to add the edge
            graph.get(n1)[1].append(n2)
        else: # need to add node and edge
            graph.update({n1:[False,[n2]]})

        if graph.get(n2): # we just need to add the edge
            graph.get(n2)[1].append(n1)
        else: # need to add node and edge
            graph.update({n2:[False,[n1]]})
   
    # remove edges to start
    for key in graph.keys():
        if "start" in graph.get(key)[1]: 
            graph.get(key)[1].remove("start")


    # now find all paths
    paths = dfsSmallTwice(graph,[],[],"start",0)
    for path in paths:
        print(path)
    
    print("number of paths through visiting one small cave twice:",len(paths))



if __name__ == "__main__":

    f = open("input","r")

    #  p1(f)

    p2(f)

    f.close()





