def p1(f):
    # what is the cheapest one to align on?
    # we want to minimize total distance traveled by each
    # crab submarine
    # for each sub calculate the sum of distances to all other subs
    # the one with the smallest sum is our target.
    # or sort the list and select the mid point as this should minimize distance

    ships = list(map(int,f.readline().split(",")))
    ships.sort()
    #  print(ships)
    #  print("midpoint:",ships[len(ships)//2])
    mid=ships[len(ships)//2]
    
    fuelcost=0;
    for i in range(len(ships)):
        fuelcost+=abs(ships[i]-mid)

    print("Total fuel cost:",fuelcost)

def cost(s,h):
    n=abs(s-h)
    return (n*(n+1))//2

def p2(f):
    # in this case distance is calculated as a summation from 1 to abs(n-m) where n and m are the subs in questions
    # naive idea: just choose the the largest number in the list as your horizontal position and calculate total cost.
    # decrease n by 1 and repeat until you no longer get a decrease in total cost by reducing n.
    # this would only really work because our input size is fairly small however. Runtime O(n^2) where n is the largest number in our input.
    # Wonder if there is a faster solution?

    ships = list(map(int,f.readline().split(",")))
    ships.sort()
    #  print(ships)
  
    # since we're gonna do something slow anyways we might as well just calc all
    # possible costs and select the min
    costList = []
    for i in range(ships[-1]):
        currentCost=0
        for ship in ships:
            currentCost+=cost(ship,i)
        costList.append(currentCost)
    costList.sort()
    print("Min cost:",costList[0])
    return 0



if __name__ == "__main__":

    f = open("input","r")

    p2(f)
