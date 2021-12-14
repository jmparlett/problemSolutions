from copy import deepcopy as dp

def p1(f):
    # lets build the manual solution
    pairDict = {}
    countDict = {}

    tempString = f.readline().strip("\n")

    f.readline() # discard newline
    for line in f.readlines():
        pair,element = line.split("->")
        pair = pair.strip()
        element = element.strip("\n").strip()
        pairDict.update({pair:element})
        countDict.update({element:0})
    
    for i in range(40):
        newTempString = ""
        for j in range(0,len(tempString)-1):
            newTempString += tempString[j]
            newTempString += pairDict.get(tempString[j]+tempString[j+1])
        newTempString += tempString[-1]
        tempString=newTempString

    for c in tempString:
        countDict[c]+=1

    vals = list(countDict.values())
    vals.sort()
    print("Most common minus least common:",vals[-1]-vals[0])
            
def p2(f):
    # every pair adds 1 new element to the array.
    # it also adds two new pairs and removes an old one
    # so however many pairs you add you now have that many new elements in the next iteration
    # the amount of elements never decreases

    # naive idea: first count elements in original string
    # count num of pairs in string 
    # then according to the rules for each pair increases the count of the element it adds
    # then decrease its count and increase the count of the two pairs it adds
    pairDict = {}
    countDict = {}

    tempString = f.readline().strip("\n")


    f.readline() # discard newline
    for line in f.readlines():
        pair,element = line.split("->")
        pair = pair.strip()
        element = element.strip("\n").strip()
        pairDict.update({pair:[element, 0, pair[0]+element, element+pair[1]]})
        countDict.update({element:0})

    # count orig elems
    for c in tempString:
        countDict[c]+=1

    # count orig pairs
    for i in range(len(tempString)-1):
        pairDict[tempString[i]+tempString[i+1]][1]+=1

    for i in range(40):
        newPairDict = dp(pairDict)
        for key in pairDict:
            pairCount = pairDict[key][1]
            countDict[pairDict[key][0]]+=pairCount # adds n of its elements
           
            # add pairs
            newPairDict[pairDict[key][2]][1]+=pairCount
            newPairDict[pairDict[key][3]][1]+=pairCount

            # remove all pairs that were in the original string
            newPairDict[key][1]-=pairCount
        pairDict=newPairDict # all this copying is a little gross *_*

    vals = list(countDict.values())
    vals.sort()
    print("Most common minus least common:",vals[-1]-vals[0])

if __name__ == "__main__":
    f = open("input","r")

    #  p1(f)
    p2(f)

    f.close()
