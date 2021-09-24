#
# Problem URL: https://www.hackerrank.com/challenges/ctci-bubble-sort/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=sorting
#
#

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'countSwaps' function below.
#
# The function accepts INTEGER_ARRAY a as parameter.
#

def countSwaps(a):
    # Write your code here
    n_swap = 0
    
    for i in range(0, len(a)):
        for j in range(0, len(a) - 1):
            if a[j] > a[j+1]:
                # Swap the integer
                temp = a[j]
                a[j] = a[j+1]
                a[j+1] = temp
                n_swap += 1
                
    
    print(f"Array is sorted in {n_swap} swaps.")
    print(f"First Element: {a[0]}")
    print(f"Last Element: {a[len(a)-1]}")
                

if __name__ == '__main__':
    n = int(input().strip())

    a = list(map(int, input().rstrip().split()))

    countSwaps(a)

