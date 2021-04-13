#!/bin/python

import sys

l = [2]
# print(2)
if len(sys.argv) == 2:
    max = int(sys.argv[1])
else:
    max = sys.maxsize
for i in range(3,max,2):
    isPrime = True
    for j in l:
        if j*j <= i:
            if i%j == 0:
                isPrime = False
                break
        else:
            break
    if isPrime:
        l.append(i)
        # print(i)
