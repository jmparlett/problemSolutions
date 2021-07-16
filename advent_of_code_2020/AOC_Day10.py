
inp=open('input.txt')
adapters=[int(i.strip()) for i in inp.readlines()]
inp.close()

adapters.sort()
adapters.insert(0,0)
adapters.append(adapters[-1]+3)

def check_numbers(n=0,memo=['n' for i in range(0,len(adapters))]):
    #List for memoization
    memo=memo

    #list of next possible steps to be tested
    arr=[]

    #Count of solutions
    count=0

    #if n at last position you have found 1 viable solution
    if n==len(adapters)-1:
        count+=1
        return count

    #Depending on position in list you have at most 3 possible steps n+1,n+2, and n+3
    elif n==len(adapters)-2:
        arr=[n+1]

    elif n==len(adapters)-3:
        arr=[n+1,n+2]

    else:
        arr=[n+1,n+2,n+3]

    #Once possibilities have been determined test them and if they are valid call recursive function
    for i in arr:
        if adapters[i]-adapters[n] <= 3:
            #if current step has been evauluated already use the recorded result in the list
            if memo[i] != 'n':
                count+=memo[i]
                print('used memo')
            else:
            #Once a solution has been found put it in the memoization list for reference in child function calls
                result=check_numbers(i,memo)
                count+=result
                memo[i]=result
                print('Didnt use memo')
            # print(check_numbers(i))
    
    #Once for loop has finished return count
    return count

print(check_numbers())
