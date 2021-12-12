def printGrid(grid):
    for row in grid:
        print("".join([str(i) for i in row]))
    print()
def flash(x,y,grid):
    # we flashed so set us to 0 and count our flash
    grid[y][x]=0
    flashes=1
    #  printGrid(grid)
    # grab all neighbors
    neighbors=[]
    if y+1 < len(grid):
        neighbors.append((y+1,x))
    if y-1 >= 0:
        neighbors.append((y-1,x)) 
    if x+1 < len(grid[0]):
        neighbors.append((y,x+1))
    if x-1 >= 0:
        neighbors.append((y,x-1))
    if y+1 < len(grid) and x+1 < len(grid[0]):
        neighbors.append((y+1,x+1))
    if y-1 >= 0 and x-1 >= 0:
        neighbors.append((y-1,x-1)) 
    if x+1 < len(grid[0]) and y-1 >= 0:
        neighbors.append((y-1,x+1))
    if x-1 >= 0 and y+1 < len(grid):
        neighbors.append((y+1,x-1))
    
    #  print("neighbor count:",len(neighbors))
    for n in neighbors:
        y,x = n
        if grid[y][x]!=0:
            grid[y][x]+=1

    for n in neighbors:
        y,x = n
        if grid[y][x]>9:
            grid,tflashes=flash(x,y,grid)
            flashes+=tflashes
    return grid,flashes


def p1(f):
    # total flash count
    flashes=0

    grid =[]
    for line in f.readlines():
        grid.append([int(line[i]) for i in range(len(line)-1)]) # skip nl
   
    for i in range(100):
        printGrid(grid)
        # first all energy levels increase by 1
        for y in range(len(grid)):
            for x in range(len(grid[0])):
                grid[y][x]+=1
        
        # now anything at 10 flashes
        for y in range(len(grid)):
            for x in range(len(grid[0])):
                if grid[y][x]>9:
                    grid,tflashes=flash(x,y,grid)
                    flashes+=tflashes

    print("Total flashes after 100 rounds:", flashes)

def p2(f):
    # total flash count

    grid =[]
    for line in f.readlines():
        grid.append([int(line[i]) for i in range(len(line)-1)]) # skip nl
    
    roundC=0 # round counter
    while True:
        roundC+=1
        flashes=0 # number of flashes this round
        printGrid(grid)
        # first all energy levels increase by 1
        for y in range(len(grid)):
            for x in range(len(grid[0])):
                grid[y][x]+=1
        
        # now anything at 10 flashes
        for y in range(len(grid)):
            for x in range(len(grid[0])):
                if grid[y][x]>9:
                    grid,tflashes=flash(x,y,grid)
                    flashes+=tflashes
        if flashes == len(grid[0])*len(grid): # then all have flashed
            printGrid(grid)
            print("Synchronus at round:",roundC)
            return


if __name__ == "__main__":

    f = open("input","r")

    #  p1(f)
    p2(f)
    f.close()
