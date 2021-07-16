puzzle_input=open('input.txt')
directions=[[i[0],int(i[1:])] for i in puzzle_input.read().split('\n')]
puzzle_input.close()

#Have 4 variables North, South, East, West which correspond to distance in that direction
#Direction changes on a L or R command given in 90 degrees or more
#A F command moves the ship in the direction it is currently facing

N=0
S=0
E=0
W=0
current_direction='E'
compass=['N','E','S','W']


def get_turns(degrees):
    turns=0
    while degrees > 0:
        turns+=1
        degrees-=90
    return turns

def increment_dir(dir,n):
    global N,S,E,W
    if dir=='N':
        N+=n
    elif dir=='S':
        S+=n
    elif dir=='E':
        E+=n
    elif dir=='W':
        W+=n
    
def move(line):
    global current_direction
    instruction=line[0]
    arg=line[1]

    #Move forward in current dir
    if instruction=='F':
        increment_dir(current_direction,arg)
    
    #To turn left subtract the number of turns from the index of your current direction this will be the index of your new direction
    elif instruction=='L':
        current_direction=compass[compass.index(current_direction)-get_turns(arg)]

    #To turn right add the number of turns to your current index in the compass else take the mod of the len of compass
    elif instruction=='R':
        if compass.index(current_direction)+get_turns(arg) > len(compass)-1:
            current_direction=compass[(compass.index(current_direction)+get_turns(arg))%len(compass)]
        else:
            current_direction=compass[compass.index(current_direction)+get_turns(arg)]
    
    #if not turning left right or going forward increment the given direction by the num desired
    else:
        increment_dir(instruction,arg)

for l in directions:
    print(current_direction)
    move(l)
    # print(N,E,S,W)

print(abs(N-S)+abs(E-W))