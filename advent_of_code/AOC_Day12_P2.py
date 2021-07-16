puzzle_input=open('input.txt')
directions=[[i[0],int(i[1:])] for i in puzzle_input.read().split('\n')]
puzzle_input.close()

#Have 4 variables North, South, East, West which correspond to distance in that direction
#Direction changes on a L or R command given in 90 degrees or more
#A F command moves the ship in the direction it is currently facing

#Ship direction values equal arg times waypoint values when input is F

N=1
S=0
E=10
W=0
quad='NE'

S_N=0
S_S=0
S_E=0
S_W=0

current_direction='E'
compass=['NW','NE','SE','SW']

def rotate_waypoint(dir,n):
    global N,S,E,W,quad
    # print(N,E,S,W)
    if dir=='R':
        if compass.index(quad)+n > len(compass)-1:
            quad=compass[(compass.index(quad)+n)%len(compass)]
        else:
            quad=compass[compass.index(quad)+n]

        while n > 0:
            t1=N
            N=E
            E=S
            S=W
            W=t1
            n-=1
    elif dir=='L':
        quad=compass[compass.index(quad)-n]
        while n > 0:
            t1=N
            N=W
            W=S
            S=E
            E=t1
            n-=1
    # print(N,E,S,W)


def get_turns(degrees):
    turns=0
    while degrees > 0:
        turns+=1
        degrees-=90
    return turns

def increment_dir(dir,n):
    global N,S,E,W,S_N,S_S,S_E,S_W,quad
    #Compass directions
    print(N,E,S,W)
    if quad=='NE':
        if dir=='N':
            N+=n
        elif dir=='S':
            N-=n
        elif dir=='E':
            E+=n
        elif dir=='W':
            E-=n

    elif quad=='NW':
        if dir=='N':
            N+=n
        elif dir=='S':
            N-=n
        elif dir=='E':
            W-=n
        elif dir=='W':
            W+=n

    elif quad=='SE':
        if dir=='N':
            S-=n
        elif dir=='S':
            S+=n
        elif dir=='E':
            E+=n
        elif dir=='W':
            E-=n

    elif quad=='SW':
        if dir=='N':
            S-=n
        elif dir=='S':
            S+=n
        elif dir=='E':
            W-=n
        elif dir=='W':
            W+=n
    print(N,E,S,W,'\n')


def move(line):
    global current_direction,S_S,S_E,S_N,S_W,S,E,N,W,quad
    instruction=line[0]
    arg=line[1]

    #Move forward in current dir
    if instruction=='F':
        S_S+=arg*S
        S_E+=arg*E
        S_N+=arg*N
        S_W+=arg*W

    elif instruction=='L':
        rotate_waypoint('L',get_turns(arg))
        print(quad)
    elif instruction=='R':
        rotate_waypoint('R',get_turns(arg))
        print(quad)
    #if not turning left right or going forward increment the given direction by the num desired
    elif instruction=='S' or instruction=='N' or instruction=='E' or instruction=='W':
        increment_dir(instruction,arg)
for l in directions:
    # print(current_direction)
    move(l)
    # print(N,E,S,W)

print(abs(S_N-S_S)+abs(S_W-S_E))
print(S_N,S_S,S_W,S_E)
print(N,S,E,W)