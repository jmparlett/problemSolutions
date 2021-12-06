def makegrid(n):
    '''returns a 2d nxn grid'''
    grid=[]
    for i in range(n):
        grid.append([0 for i in range(n)])# 0 will indicate a blank space
    return grid

def processLineSeg(seg):
    '''return points on a segment (in this case we only care about whole number point)'''
    #convert points to a workable format
    p1,p2 = seg.split("->")
    p1 = (int(p1.split(",")[0].strip()),int(p1.split(",")[1].strip()))
    p2 = (int(p2.split(",")[0].strip()),int(p2.split(",")[1].strip()))

    # in the case of x1=x2 or y1=y2 enumerating points is easy
    #x1=x2
    if p1[0]==p2[0]:
        return [(p1[0],y) for y in range(min(p1[1],p2[1]),max(p1[1],p2[1])+1)]    
    #y1=y2
    if p1[1]==p2[1]:
        return [(x,p1[1]) for x in range(min(p1[0],p2[0]),max(p1[0],p2[0])+1)]    

    # in the case where we actually have a slope we will solve the line equation
    # for all values between the two points
    m=((p1[1]-p2[1])//(p1[0]-p2[0]))
    b=p1[1]-(m*p1[0])
    initalPoint,terminalPoint=(p1 if p1[0]<p2[0] else p2),(p1 if p1[0]>p2[0] else p2)
    return [(x,m*x+b) for x in range(initalPoint[0],terminalPoint[0]+1)] 

def processLineSegHVOnly(seg):
    '''return points on a segment (in this case we only care about whole number point)'''
    #convert points to a workable format
    p1,p2 = seg.split("->")
    p1 = (int(p1.split(",")[0].strip()),int(p1.split(",")[1].strip()))
    p2 = (int(p2.split(",")[0].strip()),int(p2.split(",")[1].strip()))

    # in the case of x1=x2 or y1=y2 enumerating points is easy
    #x1=x2
    if p1[0]==p2[0]:
        return [(p1[0],y) for y in range(min(p1[1],p2[1]),max(p1[1],p2[1])+1)]    
    #y1=y2
    if p1[1]==p2[1]:
        return [(x,p1[1]) for x in range(min(p1[0],p2[0]),max(p1[0],p2[0])+1)]    
    # we dont want any non horizontals in this case
    return[]

def drawgraph(f):
    #make grid/graph
    grid = makegrid(1000)

    # draw all lines
    for lineSeg in f.readlines():
        points = processLineSeg(lineSeg)
        for point in points:
            grid[point[1]][point[0]]+=1 
    # now we can give back our fleshed out grid
    return grid


def drawgraphHVOnly(f):
    #make grid/graph
    grid = makegrid(1000)

    # draw all lines
    for lineSeg in f.readlines():
        points = processLineSegHVOnly(lineSeg)
        for point in points:
            grid[point[1]][point[0]]+=1 
    # now we can give back our fleshed out grid
    return grid

def printGrid(grid):
    for i in range(len(grid)):
        print(grid[i])

def p1(f):
    
    grid = drawgraphHVOnly(f)

    #  printGrid(grid)

    # now we count all intersections
    icount=0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] > 1:
                icount+=1
    print("count of points of intersection: ", icount)

def p2(f):
    '''basically p1 but with all lines instead of limited ones''' 
    grid = drawgraph(f)

    #  printGrid(grid)

    # now we count all intersections
    icount=0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] > 1:
                icount+=1
    print("count of points of intersection: ", icount)





if __name__ == "__main__":
    f = open("input","r")

    #  p1(f)

    p2(f)











