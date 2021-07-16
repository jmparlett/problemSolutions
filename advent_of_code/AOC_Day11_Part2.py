import copy

puzzle_input=open('input.txt')
chair_layout=[]
for i in puzzle_input.read().split('\n'):
    line=[]
    for i2 in i:
        line.append(i2)
    chair_layout.append(line)
puzzle_input.close()

def get_chair(r,c,grid):
    if grid[r][c]=='#':
        return 1
    elif grid[r][c]=='L' or grid[r][c]=='.':
        return 0
        
def c_neighbors(r,c,grid):
    count=0
    #Zero indexed grid starting at 0,0 to len(r[0])-1,len(r)-1

    #if corner
    if r==0 and c==0:
        count+=c_neighbors_ray(r,c,chair_layout,'r')
        count+=c_neighbors_ray(r,c,chair_layout,'b')
        count+=c_neighbors_ray(r,c,chair_layout,'br')
    elif r==0 and c==len(grid[r])-1:
        count+=c_neighbors_ray(r,c,chair_layout,'l')
        count+=c_neighbors_ray(r,c,chair_layout,'b')
        count+=c_neighbors_ray(r,c,chair_layout,'bl')
    
    elif r==len(grid)-1 and c==0:
        count+=c_neighbors_ray(r,c,chair_layout,'l')
        count+=c_neighbors_ray(r,c,chair_layout,'t')
        count+=c_neighbors_ray(r,c,chair_layout,'tl')
    elif r==len(grid)-1 and c==len(grid[r])-1:
        count+=c_neighbors_ray(r,c,chair_layout,'r')
        count+=c_neighbors_ray(r,c,chair_layout,'t')
        count+=c_neighbors_ray(r,c,chair_layout,'tr')

    #if all the way left
    elif c==0:
        count+=c_neighbors_ray(r,c,chair_layout,'r')
        count+=c_neighbors_ray(r,c,chair_layout,'t')
        count+=c_neighbors_ray(r,c,chair_layout,'b')
        count+=c_neighbors_ray(r,c,chair_layout,'br')
        count+=c_neighbors_ray(r,c,chair_layout,'tr')
    
    #if all the way right
    elif c==len(grid[r])-1:
        count+=c_neighbors_ray(r,c,chair_layout,'l')
        count+=c_neighbors_ray(r,c,chair_layout,'t')
        count+=c_neighbors_ray(r,c,chair_layout,'b')
        count+=c_neighbors_ray(r,c,chair_layout,'bl')
        count+=c_neighbors_ray(r,c,chair_layout,'tl')

    #if at bottom
    elif r==len(grid)-1:
        count+=c_neighbors_ray(r,c,chair_layout,'l')
        count+=c_neighbors_ray(r,c,chair_layout,'r')
        count+=c_neighbors_ray(r,c,chair_layout,'t')
        count+=c_neighbors_ray(r,c,chair_layout,'tl')
        count+=c_neighbors_ray(r,c,chair_layout,'tr')

    #if at top
    elif r==0:
        count+=c_neighbors_ray(r,c,chair_layout,'l')
        count+=c_neighbors_ray(r,c,chair_layout,'r')
        count+=c_neighbors_ray(r,c,chair_layout,'b')
        count+=c_neighbors_ray(r,c,chair_layout,'bl')
        count+=c_neighbors_ray(r,c,chair_layout,'br')

    #if within grid
    else:
        count+=c_neighbors_ray(r,c,chair_layout,'l')
        count+=c_neighbors_ray(r,c,chair_layout,'r')
        count+=c_neighbors_ray(r,c,chair_layout,'t')
        count+=c_neighbors_ray(r,c,chair_layout,'b')
        count+=c_neighbors_ray(r,c,chair_layout,'bl')
        count+=c_neighbors_ray(r,c,chair_layout,'br')
        count+=c_neighbors_ray(r,c,chair_layout,'tl')
        count+=c_neighbors_ray(r,c,chair_layout,'tr')

    return count

def c_neighbors_ray(r, c, grid, d):
    count=0

    if d=='l':
        #Check left
        while c > 0:
            c-=1
            if grid[r][c]=='#':
                count+=1
                break
            elif grid[r][c]=='L':
                break

    if d=='r':
        #Check right
        while c < len(grid[0])-1:
            c+=1
            if grid[r][c]=='#':
                count+=1
                break
            elif grid[r][c]=='L':
                break

    if d=='t':
        #check top
        while r > 0:
            r-=1
            if grid[r][c]=='#':
                count+=1
                break  
            elif grid[r][c]=='L':
                break

    if d=='b':
        #check bottom
        while r < len(grid)-1:
            r+=1
            if grid[r][c]=='#':
                count+=1
                break    
            elif grid[r][c]=='L':
                break

    if d=='tl':
        #top left diag
        while c > 0 and r > 0:
            r-=1
            c-=1
            if grid[r][c]=='#':
                count+=1
                break
            elif grid[r][c]=='L':
                break

    if d=='tr':
        #top right diag
        while c < len(grid[0])-1 and r > 0:
            c+=1
            r-=1
            if grid[r][c]=='#':
                count+=1
                break
            elif grid[r][c]=='L':
                break

    if d=='bl':
        #bottom left diag
        while c > 0 and r < len(grid)-1:
            c-=1
            r+=1
            if grid[r][c]=='#':
                count+=1
                break
            elif grid[r][c]=='L':
                break

    if d=='br':
        #bottom right diag
        while c < len(grid[0])-1 and r < len(grid)-1:
            c+=1
            r+=1
            if grid[r][c]=='#':
                count+=1
                break
            elif grid[r][c]=='L':
                break

    return count

def update(grid):
    grid2=copy.deepcopy(grid)
    for r in range(0,len(grid)):
        for c in range(0,len(grid[0])):
            # print(r,c)
            if grid[r][c]=='.':
                pass
            elif grid[r][c]=='#':
                # print(c_neighbors(r,c,grid))
                if c_neighbors(r,c,grid) > 4:
                    grid2[r][c]='L'
                else:
                    grid2[r][c]='#'
            elif grid[r][c]=='L':
                # print(c_neighbors(r,c,grid1))
                if c_neighbors(r,c,grid)==0:
                    grid2[r][c]='#'
                else:
                    grid2[r][c]='L'
    # print(grid)
    return grid2

def count_occ(grid):
    occ=0
    for i in grid:
        for i2 in i:
            if i2=='#':
                occ+=1
    print(occ)

for i in range(0,100):
    chair_layout=update(chair_layout)
    count_occ(chair_layout)

# print(c_neighbors_ray(20,50,chair_layout,'l'))
# print(c_neighbors_ray(20,50,chair_layout,'r'))
# print(c_neighbors_ray(20,50,chair_layout,'t'))
# print(c_neighbors_ray(20,50,chair_layout,'b'))
# print(c_neighbors_ray(20,50,chair_layout,'bl'))
# print(c_neighbors_ray(20,50,chair_layout,'br'))
# print(c_neighbors_ray(20,50,chair_layout,'tl'))
# print(c_neighbors_ray(20,50,chair_layout,'tr'))


out=open('output.txt', 'a')
for i in chair_layout:
    line=''
    for i2 in i:
        line+=i2
    line+='\n'
    out.writelines(line)
# print(c_neighbors(97,0,chair_layout))