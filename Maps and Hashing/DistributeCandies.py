# Leetcode Question : 575
# URL : https://leetcode.com/problems/distribute-candies/description/

#!/usr/bin/env python
import collections
import sys

def distribute(candies = [1,1,2,2,3,3,4,5,6,7,8,9,9,9,9,9,10,10]):
    unique_candies = set()
    for candy in candies:
        unique_candies.add(candy)
    return min(len(candies)/2, len(unique_candies))

if __name__ == '__main__':
    print distribute()
