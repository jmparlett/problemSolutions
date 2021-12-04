def p1(f):
    '''Takes a file object to read input from'''

    #need to count bits on in each column and take the greatest
    inf = f.read()
    coloff=13

    gamma=0
    gi=11
    for i in range(12): #dont need nl
        oc=0
        for j in range(1000):
            oc+=int(inf[j*coloff + i])
        if oc > 500:
            gamma |= (1 << gi)
        gi-=1
    print(gamma * ((~gamma)&(~(~0<<12))))
    return gamma

def p2helper(lines,bitidx,switch): #switch determines if we keep least or most common
    if len(lines) == 1:
        return lines[0]
    olist=[]
    zlist=[]
    print(bitidx)
    for l in lines:
        olist.append(l) if l[bitidx]=='1' else zlist.append(l)
    
    if len(olist) >= len(zlist) and switch:
        return p2helper(olist,bitidx+1,switch)
    elif switch:
        return p2helper(zlist,bitidx+1,switch)
    elif len(zlist) <= len(olist) and ~switch:
        return p2helper(zlist,bitidx+1,switch)
    else:
        return p2helper(olist,bitidx+1,switch)


def p2(f):
    '''Takes a file object to read input from'''

    lines = [l.strip('\n') for l in f.readlines()]

    print(int(p2helper(lines,0,1),2) * int(p2helper(lines,0,0),2))


if __name__ == "__main__":
    f = open("input","r")
   
    #  p1(f)
    p2(f)

    f.close()
