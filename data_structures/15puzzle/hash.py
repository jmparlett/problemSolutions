from itertools import permutations as perms
from math import factorial as f
#need a hash function that is sensitive to position, unique to a sequence, but not a set
#
# 1. multiple each int by its index
# 2. sum this result
# 3. mod size of table = position in table

# lets make a function to test the collision stats for this idea

#  def hash(seq, n, size):
    #  h=0
    #  for i in range(len(seq)):
        #  for j in range(4):
            #  h|=((seq[i])<<(4*i))
    #  return (h*393241)%size

def hash(seq, n, k, size):
    S=0
    c=0
    b=0 #byte index
    for i in range(n):
        for j in range(k):
            if b==32:
                b=0
                S+=(c*193&0xffffffff)
                #  print(chr(c), end='')
                c=0
            c |= ((seq[i]>>j)&1)<<b
            b+=1
        #  print('\n')
    return ((S*769)&0xffffffff)%size

# need to generate all possible orders of 9 nums so 9! nums
P = set(perms([1,2,3,4,5,6,7,8,0]))

# dict = our hash table
D = {}

totalAdded=0

collisions=0

for i in P:
    h = hash(i, len(i), 4, f(9))
    if D.get(h) is None:
        D.update({h:[i]})
    else:
        D.get(h).append(i)
        collisions+=1
    totalAdded+=1

keys = D.keys()
listsUsed=0
for k in keys:
    l = len(D.get(k))
    if l != 0:
        print("list ",k," contains ", l, " vals")
        listsUsed+=1

print("total lists used: ",listsUsed)
print("total added: ", totalAdded)
print("total collisions: ", collisions)
print("percent collisions: ", collisions/totalAdded)
