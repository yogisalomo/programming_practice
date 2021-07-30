# Link: https://www.hackerrank.com/challenges/one-week-preparation-kit-plus-minus/problem?h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=one-week-preparation-kit&playlist_slugs%5B%5D=one-week-day-one

# !/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'plusMinus' function below.
#
# The function accepts INTEGER_ARRAY arr as parameter.
#

def plusMinus(arr):
    # Write your code here
    n_pos = 0
    n_neg = 0
    n_zero = 0

    for num in arr:
        if num > 0:
            n_pos += 1
        elif num < 0:
            n_neg += 1
        else:
            n_zero += 1

    print("%.6f" % (n_pos / len(arr)))
    print("%.6f" % (n_neg / len(arr)))
    print("%.6f" % (n_zero / len(arr)))


if __name__ == '__main__':
    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    plusMinus(arr)
