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
    top=r-1
    bottom=r+1
    left=c-1
    right=c+1

    #if corner
    if r==0 and c==0:
        count+=get_chair(r,right,grid)
        count+=get_chair(bottom,right,grid)
        count+=get_chair(bottom,c,grid)
    elif r==0 and c==len(grid[r])-1:
        count+=get_chair(r,left,grid)
        count+=get_chair(bottom,left,grid)
        count+=get_chair(bottom,c,grid)
    
    elif r==len(grid)-1 and c==0:
        count+=get_chair(r,right,grid)
        count+=get_chair(top,right,grid)
        count+=get_chair(top,c,grid)
    elif r==len(grid)-1 and c==len(grid[r])-1:
        count+=get_chair(r,left,grid)
        count+=get_chair(top,left,grid)
        count+=get_chair(top,c,grid)

    #if all the way left
    elif c==0:
        count+=get_chair(top,c,grid)
        count+=get_chair(top,right,grid)
        count+=get_chair(r,right,grid)
        count+=get_chair(bottom,c,grid)
        count+=get_chair(bottom,right,grid)
    
    #if all the way right
    elif c==len(grid[r])-1:
        count+=get_chair(top,c,grid)
        count+=get_chair(top,left,grid)
        count+=get_chair(r,left,grid)
        count+=get_chair(bottom,c,grid)
        count+=get_chair(bottom,left,grid)

    #if at bottom
    elif r==len(grid)-1:
        count+=get_chair(top,right,grid)
        count+=get_chair(top,left,grid)
        count+=get_chair(top,c,grid)
        count+=get_chair(r,left,grid)
        count+=get_chair(r,right,grid)

    #if at top
    elif r==0:
        count+=get_chair(bottom,right,grid)
        count+=get_chair(bottom,left,grid)
        count+=get_chair(bottom,c,grid)
        count+=get_chair(r,left,grid)
        count+=get_chair(r,right,grid)
    
    #if within grid
    else:
        count+=get_chair(bottom,right,grid)
        count+=get_chair(bottom,left,grid)
        count+=get_chair(bottom,c,grid)
        count+=get_chair(r,left,grid)
        count+=get_chair(r,right,grid)
        count+=get_chair(top,right,grid)
        count+=get_chair(top,left,grid)
        count+=get_chair(top,c,grid)

    return count

def c_neighbors_ray(r, c, grid):
    count=0
    #check top
    while r >= 0:
        r-=1
        if grid[r][c]=='#':
            count+=1
            break
    
    #check bottom
    while r <= len(grid)-1:
        r+=1
        if grid[r][c]=='#':
            count+=1
            break
    
    #Check left
    while c >= 0:
        c-=1
        if grid[r][c]=='#':
            count+=1
            break

    #Check right
    while c <= len(grid[0]-1):
        c+=1
        if grid[r][c]=='#':
            count+=1
            break

    #top left diag
    while c >= 0 and r >= 0:
        r-=1
        c-=1
        if grid[r][c]=='#':
            count+=1
            break
    
    #top right diag
    while c <= len(grid[0])-1 and r >= 0:
        c+=1
        r-=1
        if grid[r][c]=='#':
            count+=1
            break
    
    #bottom left diag
    while c >= 0 and r <= len(grid)-1:
        c-=1
        r+=1
        if grid[r][c]=='#':
            count+=1
            break
    
    #bottom right diag
    while c <= len(grid[0])-1 and r <= len(grid)-1:
        c+=1
        r+=1
        if grid[r][c]=='#':
            count+=1
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

# for i in range(0,100):
#     chair_layout=update(chair_layout)
#     count_occ(chair_layout)

print(c_neighbors_ray(5,6,chair_layout))


# out=open('output.txt', 'a')
# for i in test:
#     line=''
#     for i2 in i:
#         line+=i2
#     line+='\n'
#     out.writelines(line)
# print(occ)
# # print(c_neighbors(97,0,chair_layout))