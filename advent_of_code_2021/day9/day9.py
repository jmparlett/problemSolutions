def checkTile(x,y,grid):
    # check if tile is min of neighbors
    # neighbors at (x+1,y), (x-1,y), (x,y+1), (x,y-1)
    neighbors=[]
    if y+1 < len(grid):
        neighbors.append(grid[y+1][x])
    if y-1 >= 0:
        neighbors.append(grid[y-1][x]) 
    if x+1 < len(grid[0]):
        neighbors.append(grid[y][x+1])
    if x-1 >= 0:
        neighbors.append(grid[y][x-1])
    for n in neighbors:
        if grid[y][x] >= n:
            return False
    return True

def p1(f):
    # This sounded a little confusing at first, but it seems like key takeaway is "The locations that are lower than any of its adjacent locations."
    # So check adjacents, if is the min of all its neighbors then it gets picked other wise it doesn't. This means that some rows and a large amount of columns
    # wont have any mins.

    grid=[]
    for line in f.readlines():
        grid.append([int(line[i]) for i in range(len(line)-1)]) # -1 so we skip the nl
   
    print(grid)
    riskSum=0

    # now we calculate all mins and add to our risk sum
    for y in range(len(grid)):
        for x in range(len(grid[0])):
                if checkTile(x,y,grid):
                    riskSum += (grid[y][x]+1)
    print("Sum of all risk levels:",riskSum)

def basinSize(x,y,grid):
    # calculate basin size recursively
     
    # count all neighbors that havent been touched
    grid[y][x][1]=True# we count ourselves as explored
    count=1
    neighbors=[]
    if y+1 < len(grid):
        neighbors.append((y+1,x))
    if y-1 >= 0:
        neighbors.append((y-1,x)) 
    if x+1 < len(grid[0]):
        neighbors.append((y,x+1))
    if x-1 >= 0:
        neighbors.append((y,x-1))
    for n in neighbors:
        y,x = n
        if not grid[y][x][1] and grid[y][x][0]!=9:# flag=false and we're not at a border
            grid, tcount = basinSize(x,y,grid)
            count+=tcount
    return grid,count 

def p2(f):
    # Now we need to find all basins. A basin is determined by a low point a border of 9s or the end of the grid.
    # 

    grid=[]
    for line in f.readlines():
        grid.append([[int(line[i]),False] for i in range(len(line)-1)]) # -1 so we skip the nl
  
    basins = []
    # now for each low point we calculate its basin size
    for y in range(len(grid)):
        for x in range(len(grid[0])):
                if checkTile(x,y,grid):
                    basins.append(basinSize(x,y,grid)[1])
   
    basins.sort()

    print(basins)
    prod=1
    for i in range(len(basins)-1, len(basins)-4,-1):
        prod*=basins[i]

    print("Largest basin product:",prod)
if __name__ == "__main__":
    f = open("input","r")

    #  p1(f)
    p2(f)
