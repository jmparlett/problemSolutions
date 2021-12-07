def p1(f):
    
    lanternschool = list(map(int,f.readline().split(",")))

    for i in range(80): # need population after 80 days
        newFish=0
        prevlen=len(lanternschool)
        for j in range(len(lanternschool)):
            if lanternschool[j]==0:
                newFish+=1
                lanternschool[j]=6 # old fish get reset to 6
            else:
                lanternschool[j]-=1
        #  print(lanternschool)
        # add all the new fish
        lanternschool+=[8 for i in range(newFish)] 
        print(len(lanternschool)-prevlen) 
        #  print("current iter: ",i)
    print("Final fish count: ",len(lanternschool))

def p2(f):
    '''
    googled for this one :(
    The idea is simply track how many will be generated at each day, then interpret all days as a cycle.
    '''
    lanternschool = list(map(int,f.readline().split(",")))

    fish = [0 for i in range(9)]

    for f in lanternschool:
        fish[f]+=1

    for i in range(256):
        fish[((i%len(fish))+7)%len(fish)]+=fish[i%len(fish)]

    print("final count:",sum(fish))

if __name__ == "__main__":
    f = open("input","r")

    #  p1(f)

    p2(f)
