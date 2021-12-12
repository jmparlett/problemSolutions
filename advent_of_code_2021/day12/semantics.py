from copy import copy as cp
from copy import deepcopy as dp
l = [1,2,3]

def ap(l):
    l.append(4) # this leaves l with an extra 4
    print("list in ap:",l)

def apc(l):
    cp(l).append(4)
    print("list in apc:",l)

def apdp(l):
    dp(l).append(4)
    print("list in apdp:",l)


if __name__ == "__main__":

    print("list at start:",l)

    ap(l)

    print("list after ap:",l)

    apc(l)

    print("list after apc:",l)

    apdp(l)
    print("list after apdp:",l)


