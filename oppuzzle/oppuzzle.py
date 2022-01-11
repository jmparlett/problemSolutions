#!/usr/bin/env python
# -*- coding: utf-8 -*-
#Author: Jonathan Parlett
#Program Name: oppuzzle
#Created: 2022-January-10
from itertools import permutations
import sys

'''
Can you solve this puzzle?

Use each of the numbers 1, 3, 4, and 6 exactly once with any
of the four basic math operations (addition, subtraction,
multiplication, and division) to total 24. Each number must be
used once and only once, and you may define the order of
operations; for example, 3 * (4 + 6) + 1 = 31 is valid, however
incorrect, since it doesn’t total 24.

Well I couldn't so I brute forced it (-_-)
'''

opf = open("ops.txt", "r")
nums = "1346"


operations = [line.strip("\n") for line in opf.readlines()]

opf.close()

if __name__ == "__main__":
    #the permuations of the operations matters because it is with repetitions, it changes, but the
    # numbers are always the same, so we don't need to permute them out side this loop
    # so the goal now is to generate all permutations of operators+numbers and evaluate them
    # as prefix notations
    # we could cut this down by only pick the unique perms with reps of the operations, but its a pretty small search space
    # so who cares
    for oline in operations:
        # this will generate some invalid expressions
        perms = list(permutations(oline+nums))
        # instead of checking the expression we'll just try to evaluate, and if we get an error we know it wasn't valid
        for perm in perms:
            stack = []
            try:
                for s in perm:
                    if s.isnumeric():
                        stack.append(s)
                    else:
                        stack.append(eval("{}{}{}".format(stack.pop(),s,stack.pop())))
                r = stack.pop()
                if float(r)==24.0:
                    print(perm," = ",r)
                    sys.exit(0)
            except Exception:
                pass
