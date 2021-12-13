def makepaper(f):
    points = []
    folds = []
    pointLines=[]
    foldLines=[]
   
    while True:
        line = f.readline()
        if line=="\n":
            break
        pointLines.append(line)

    for line in f.readlines():
        foldLines.append(line)

    for line in foldLines:
        d,val = line.split()[2].split("=")
        val = int(val)
        d = 0 if d=='x' else 1
        folds.append((d,val))
    
    for line in pointLines:
        x,y = tuple(map(int,line.strip("\n").split(",")))
        points.append((x,y))

    mx = points[0][0]
    my = points[0][1]
    
    for point in points:
        if point[0] > mx:
            mx = point[0]
        if point[1] > my:
            my = point[1]
    
    paper = [((mx+1)*[0]) for i in range(my+1)]

    for point in points:
        x,y = point
        paper[y][x]=1
    return paper,folds
    
def slice(paper,fold):
    direction,position = fold

    if direction == 0: # slicing in x
        partition = []
        for i in range(len(paper)):
            paper[i], pline = paper[i][:position], paper[i][:position:-1]
            partition.append(pline) # this is now the all relevent sections reversed

        # now we need to OR in each line of our partition starting at the difference of the col length
        start = abs(len(paper[0])-len(partition[0]))
        for i in range(len(paper)): # for all the rows
            for j in range(start,len(paper[0])):
                    paper[i][j]|=partition[i][j-start]
    else: # slicing in y
        partition = paper[:position:-1]
        paper = paper[:position]
        start = abs(len(paper)-len(partition))

        for i in range(start,len(paper)):
            for j in range(len(paper[0])):
                    paper[i][j]|=partition[i-start][j]
    # return folded paper
    return paper

def printPaper(paper):
    for line in [[("#" if i==1 else ".") for i in l] for l in paper]:
        print("".join(line))

def p1(f):
    # paper needs to be accurate horizontally, so the last column 
    # should be the max of x in our input and the last row should be max of y

    paper,folds = makepaper(f)

    # now fold the paper once and count the dots
    paper = slice(paper,folds[0])

    dots=0
    for y in range(len(paper)):
        for x in range(len(paper[0])):
                dots+=paper[y][x]
    
    print("Num dots after first fold:",dots)

def p2(f):
    # now we just need to fold entirely and print the result
    paper,folds = makepaper(f)

    for fold in folds:
        paper = slice(paper,fold)

    printPaper(paper)
if __name__ == "__main__":
    
    f = open("input","r")

    #  p1(f)
    
    p2(f)
    f.close()
