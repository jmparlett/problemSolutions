def grabRanges(f):
    s=f.readline().strip('\n').split()
    xr = tuple(map(int,s[2].strip(',').strip("x=").split("..")))
    yr = tuple(map(int,s[3].strip("y=").split("..")))
    return xr,yr

def p1(f):
    # parse for range
    # plot a x,y velocity combo
    # if it lands in target area its max height is recorded
    
    xr, yr = grabRanges(f)
    print(xr,yr)    

    # the corners of our grid can basically be the ranges given
    # since if we overshoot them then we've already failed
    # x between 0 and xr[1]
    # y between 

    #solution here is actually really simple
    #the highest y you can achive is to move up from the trench in increments
    #of velocity_y or 1 so -115 + (-115 + 1) + (-115 +2), etc
    print("Max y:", min(yr)*(min(yr)+1)/2)

def p2(f):
    xr, yr = grabRanges(f)

    #max v_y is yr[1] since that will immediately move us to our max point and 2 iterations later move us to the bottom of the trench
    #max v_x is just xr[1] since that will just move us the the end of our goal square
    #min v_x is just 0 (obviously anything negative will be useless to us)
    #min v_y is -yr[1] since it will immediately take us to the bottom of the trench
    #so lets brute force these values and see which ones end up in the range
    
    print(xr,yr)

    velocityCount=0
    velocityList = []
    print("max xr:",max(xr))
    print("min yr:",min(yr))
    for v_x in range(max(xr)+1):
        for v_y in range(-abs(min(yr)),(abs(min(yr))+1)):
            vx,vy = v_x,v_y
            x,y = 0,0
            #  print(v_x,v_y)
            while True:
                x+=vx
                y+=vy
                vy-=1
                if vx < 0:
                    vx+=1
                elif vx > 0:
                    vx-=1
                # check for success or failure
                if x >= min(xr) and x <= max(xr) and y <= max(yr) and y >= min(yr):
                    #  print(x,y)
                    velocityList.append((v_x,v_y))
                    velocityCount+=1
                    break
                if (x > max(xr)) or (vx == 0 and x < min(xr)) or (vy < 0 and y < min(yr)):
                    break
    print(velocityList)
    print("Velocity Count:",velocityCount)


if __name__ == "__main__":
    f = open("input","r")

    #  p1(f)

    p2(f)

    f.close()
