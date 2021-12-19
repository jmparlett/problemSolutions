from math import ceil
# lot of googleing for this soltuion I think this is my last problem of the year 8_8

class Node:
    def __init__(self,val=None):
        self.val=val
        self.left = None
        self.right = None
        self.par = None

def printTree(root):
    if root is None:
        return
    #  print("[",end='')
    printTree(root.left)
    if root.val != None:
        print(root.val,end=' ')
    printTree(root.right)
    #  print("]",end='')
def parsetotree(l):
    # take a list and parse to a tree
    root = Node()
    if isinstance(l,int):
        root.val = l
        return root

    root.left = parsetotree(l[0])
    root.right = parsetotree(l[1])
    root.left.par = root
    root.right.par = root

    return root

def split(node):
    node.left = Node(node.val//2)
    node.right = Node(ceil(node.val/2))
    node.left.par = node
    node.right.par = node

    node.val = None

def explode(node):
    # assume we were given a node of depth 3 with a two children
    leftsibling = node.par
    prev_node = node
    while (leftsibling != None) and leftsibling.left == prev_node:
        prev_node = leftsibling
        leftsibling = leftsibling.par
    
    if leftsibling != None: # we have a sibling because we found an ancestor with a left child
        leftsibling = leftsibling.left
        while leftsibling.val == None:
            if leftsibling.right != None:
                leftsibling=leftsibling.right
            else:
                leftsibling=leftsibling.left
        leftsibling.val += node.left.val

    rightsibling = node.par
    prev_node = node
    while (rightsibling != None) and rightsibling.right == prev_node:
        prev_node = rightsibling
        rightsibling = rightsibling.par

    if rightsibling != None:
        rightsibling = rightsibling.right
        while rightsibling.val == None:
            if rightsibling.left != None:
                rightsibling=rightsibling.left
            else:
                rightsibling=rightsibling.right
        rightsibling.val += node.right.val

    node.val = 0
    node.left = None
    node.right = None


def dfs(root, depth, searchtype):
    if root == None:
        return root

    condition = (root.left == None and root.right == None) or (
            root.left.val != None and root.right.val != None)

    if searchtype: # search for node of depth 4
        if depth == 4 and root.val == None and condition: # have a node with a embedded list
            return root
        else:
            target = dfs(root.left,depth+1,searchtype)
        if target != None:
            return target
        else:
            return dfs(root.right,depth+1,searchtype)
    else: # find node with val greater than 9
        if root.val != None and root.val > 9:
            return root
        target = dfs(root.left,depth+1,searchtype)
        if target != None:
            return target
        else:
            return dfs(root.right,depth+1,searchtype)

def reduce(root):
    # try to explode
    node = dfs(root,0,1)
    if node != None:
        explode(node)
        root = reduce(root)
    # try to split a node
    node = dfs(root,0,0)
    if node != None:
        split(node)
        root = reduce(root)
    return root

def add(t1,t2):
    root = Node()
    root.left = t1
    root.right = t2
    root.left.par = root
    root.right.par = root
    reduce(root)
    return root

def magnitude(node):
    if node.val != None:
        return node.val
    return 3 * magnitude(node.left) + 2 * magnitude(node.right)


def p1(f):
    numlist = [eval(line.strip('\n')) for line in f.readlines()]


    # transform numlist to list of tree
    numlist = [parsetotree(num) for num in numlist]
    for tree in numlist:
        printTree(tree)
        print()
    currentNum = numlist[0]
    numlist = numlist[1:]
    while numlist != []:
        currentNum = add(currentNum,numlist[0])
        numlist = numlist[1:]
    printTree(currentNum)
    print()
    print(magnitude(currentNum))

def p2(f):
    numlist = [eval(line.strip('\n')) for line in f.readlines()]

    maxMag = 0
    for i in range(len(numlist)):
        for j in range(len(numlist)):
            if i != j:
                magsum = magnitude(add(parsetotree(numlist[i]),parsetotree(numlist[j])))
                if magsum > maxMag:
                    maxMag = magsum
    print("Max magnitude:",maxMag)

if __name__ == "__main__":
    f = open("input","r")

    #  p1(f)
    p2(f)
    f.close()
