#
# Problem URL: https://www.hackerrank.com/challenges/count-triplets-1/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dictionaries-hashmaps
#

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the countTriplets function below.
def countTriplets(arr, r):
    count = 0
    num_occurrence = {}
    pair_occurence = {}
    
    for num in reversed(arr):
        if num * r in pair_occurence:
            count+= pair_occurence[num*r]
        
        if num * r in num_occurrence:
            pair_occurence[num] = pair_occurence.get(num,0) + num_occurrence[num*r]
        
        num_occurrence[num] = num_occurrence.get(num, 0) + 1
    
    return count
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nr = input().rstrip().split()

    n = int(nr[0])

    r = int(nr[1])

    arr = list(map(int, input().rstrip().split()))

    ans = countTriplets(arr, r)

    fptr.write(str(ans) + '\n')

    fptr.close()

