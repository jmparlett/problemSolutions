def p1(f):
    # nums and corresponding number of sig groups
    #0:6 1:2 2:5 3:5 4:4 5:5 6:6 7:3 8:7 9:6
    #uniques
    #1:2 4:4 7:3 8:7

    # Part 1 only asks us to figure out the digits with unique number of sig groups
    
    # We'll use a dictionary for sig groups
    D = {2:1, 4:4, 3:7, 7:8}

    signals = []
    for line in f.readlines():
        signals += line.split("|")[1].split()
     
    # now we count digits in the stream that we can understand
    count=0
    for signal in signals:
        if D.get(len(signal)) != None:
            count+=1
    print("Number of 1,4,7 and 8s:",count)

def p2(f):
    # now we have to decode everything

    # We can know 1,4,7,8. We can figure out 6 from 1 becuase there will be one char in 1 not in 6
    # and that is not true for 0 and 9 they will contain 6
    # between 9 and 0, 9 will contain 4 while 0 will not so we can find 0 using 4 and the remaining
    # string of len 6 must be 9

    # for strings of len 5 namely 2, 3, and 5
    # We can use 6 to find 5 since there will be only one char in 6 not in 5 and the same is not
    # true of 2 and 3 (they differ from 6 by more than 1)
    # between 2 and 3, 3 will contain 1 while 2 will not
    # the remaining string is 2

    outputSum=0

    D = {2:1, 4:4, 3:7, 7:8}

    for line in f.readlines():
        outputs = line.split("|")[1].split()
        allsigs = line.split("|")[0].split()

        # because things are scrambled lets just sort everything before we start processing
        outputs[:] = [''.join(sorted(o)) for o in outputs]
        allsigs[:] = [''.join(sorted(sig)) for sig in allsigs]
        # store what we know from the start
        table = {}
        
        for sig in allsigs:
            if D.get(len(sig)) != None:
                table.update({sig:D.get(len(sig))})
                table.update({D.get(len(sig)):sig})
    
        for sig in allsigs:
            # strings of len 6 
            if len(sig) == 6:
                if len(set(table[1])-set(sig))==1:
                    table.update({sig:6})
                elif len(set(table[4])-set(sig))==0:
                    table.update({sig:9})
                else:
                    table.update({sig:0})
            # strings of len 5
            elif len(sig) == 5:
                if len(set(table[1])-set(sig))==0: # we have 3
                    table.update({sig:3})
                elif len(set(table[4])-set(sig))==1: # we have 5
                    table.update({sig:5})
                else: #we have 2
                    table.update({sig:2})

        # some lazy python stuff
        num=''
        for o in outputs:
            num+=str(table[o])
        outputSum+=int(num)
       
    print("Sum of all output vals:",outputSum)

if __name__ == "__main__":

    f = open("input","r")

    #  p1(f)

    p2(f)
