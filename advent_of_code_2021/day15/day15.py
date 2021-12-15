from queue import PriorityQueue as pq

def getNeighbors(grid, cr, cc):
    neighbors = []
    if cr+1 < len(grid):
        neighbors.append((cr+1,cc))
    if cc+1 < len(grid):
        neighbors.append((cr,cc+1))
    if cr > 0:
        neighbors.append((cr-1,cc))
    if cc > 0:
        neighbors.append((cr,cc-1))
    return neighbors

def dijkastra(grid):
    # tuples compare based on first element so we store nodes as in heap as (distance,ROW,COL)
    heap = pq()

    grid[0][0][2]=0 # distance = 0
    heap.put((grid[0][0][2],0,0)) # top left corner

    while not heap.empty():
        #  print(heap.queue)
        distance,cr,cc= heap.get()
        #  grid[cr][cc][1]=True # mark as visited

        # add neighbors to queue if not visited and update their distance
        for n in getNeighbors(grid,cr,cc):
            ncr,ncc = n
            # relax edge
            if grid[ncr][ncc][2] > distance + grid[ncr][ncc][0]:
                grid[ncr][ncc][2]= distance + grid[ncr][ncc][0]
                grid[ncr][ncc][3]=(cr,cc)

            if grid[ncr][ncc][1] is False:
                # add to queue sorted by distance
                heap.put((grid[ncr][ncc][2],ncr,ncc))
                grid[ncr][ncc][1] = True # mark as dicovered
            # check for term condition
            if ncr == len(grid)-1 and ncc == len(grid[0])-1:
                print("Lowest cost to bottom left:",grid[len(grid)-1][len(grid[0])-1][2])
                return
        # why do graph algos always end up looking like spaghetti code?

                
def printPath(grid,cr,cc):
    if grid[cr][cc][3]==-1:
        print((cr,cc),"cost:",grid[cr][cc][0])
    else:
        pr,pc = grid[cr][cc][3]
        printPath(grid,pr,pc)
        print((cr,cc),"cost:",grid[cr][cc][0])

def p1(f):
    # grid search problem, need optimizations
    # nodes stored as [cost,visited,distance,pred], highest cost in the grid is sum of all nodes = O(9*100*100) < 2^32
    grid = [[[int(i),False,2**32,-1] for i in line.strip("\n")] for line in f.readlines()]
    #  print(grid)

    dijkastra(grid)


def buildGrid(f):
    # now we need to extend the grid
    grid = [[int(i) for i in line.strip("\n")] for line in f.readlines()]

    # lets extend it horizontally first
    newGrid = []
    for i in range(len(grid)):
        newLine = []
        for j in range(5):
           newLine += [((k+j) if (k+j)<10 else (k+j)%9) for k in  grid[i]]
        newGrid.append(newLine)
    
    grid = newGrid
    # now vertically
    newGrid = [] 
    for j in range(5):
        for line in grid:
            newGrid.append([[((k+j) if (k+j)<10 else (k+j)%9),False,2**32,-1] for k in line])
    return newGrid

def p2(f):

    grid = buildGrid(f)


    dijkastra(grid)

if __name__ == "__main__":
    f = open("input","r")

    #  p1(f)
    p2(f)

    f.close()
















