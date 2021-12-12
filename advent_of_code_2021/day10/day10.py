def findErrorAlmostRight(line,D):
    # first char in line should be sibling of target
    print(line)
    char=line[0]

    target=''
    if D.get(chr(ord(char)+1))!=None:
        target=chr(ord(char)+1)
    elif D.get(chr(ord(char)+2))!=None:
        target=chr(ord(char)+2)
    else: #its not in list
        return D.get(char)
    
    print(char,target)
    for i in range(1,len(line)):
        if line[i]==target: # we found the correct sibling so lets slice and recurse
            return findError(line[1:i]+line[i+1:],D)
    return D.get(target)
    
def findError(line,D):
    stack = []
    for char in line:
        if D.get(char)!=None:
            if chr(ord(stack[-1])+1)==char or chr(ord(stack[-1])+2)==char:
                stack.pop()
            else:
                return D.get(char)
        else:
            stack.append(char)
    print(stack)
    return 0
def p1(f):
    # We need to find all syntax errors in each line. In the first line the syntax
    
    pointDict = {")":3,"]":57,"}":1197,">":25137}

    # naive idea: for char in the line find its appropriate match and remove both from the line
    # if a char doesn't have a good match then it is the illegal and we calc its points
    # once we find an illegal we add it to the sum and continue to the next line
    # if a line eventually becomes empty then it is not illegal

    # Better idea: first we check if a chars "sibling" is in our list. "(" sibling would be but ")" would not.
    # If positive then we search line for sibling. If we dont find it we return cost of sibling.
    # If negative we return cost of char since it must be in our list itself.
    # else if no chars left we return 0 (it was a valid line)
    # this doesn't work because it only find the first opener that is incorrect, it does not find what the opener matched
   
    # the right idea: This is a stack problem. If the current char is an opening char "(" we push to the stack
    # if it is one of the closing chars then we check if it matches what is on the top of the stack and pop and continue if it matches.
    # if it doesn't we've found our incorrect char.

    errorSum=0
    lines = [list(l.strip('\n')) for l in f.readlines()]
     
    for line in lines:
        errorSum+=findError(line,pointDict)

    print("Sum of syntax error cost:",errorSum)

def findErrorsReturnStack(line,D):
    stack = []
    for char in line:
        if D.get(char)!=None:
            if chr(ord(stack[-1])+1)==char or chr(ord(stack[-1])+2)==char:
                stack.pop()
            else:
                return stack,D.get(char)
        else:
            stack.append(char)
    return stack,0


def p2(f):
    lines = [list(l.strip('\n')) for l in f.readlines()]
    pointDict = {")":3,"]":57,"}":1197,">":25137}
    completionPointDict = {"(":1,"[":2,"{":3,"<":4}

    # Knowing this is a stack problem makes this easy. Whatever is left in our stack after completing the first process
    # is what needs to be completed. And the last thing in the stack is the first to be completed.
    completionScores = []
    for line in lines:
        stack,errors=findErrorsReturnStack(line,pointDict)
        if errors==0:# we have an incomplete line
            score=0
            while stack:
                score*=5
                score+=completionPointDict.get(stack.pop())
            completionScores.append(score)
    
    completionScores.sort()
    print(completionScores[len(completionScores)//2])
if __name__ == "__main__":
    
    f = open("input","r")

    #  p1(f)
    p2(f)
