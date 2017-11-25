/*
Leetcode Problem 693. Binary Number with Alternating Bits
Given a positive integer, check whether it has alternating bits
*/

class Solution(object):
    def hasAlternatingBits(self, n):
        """
        :type n: int
        :rtype: bool
        """
        flag = 1 if n % 2 == 1 else 0
        while n > 0:
            if n % 2 == flag:
                flag = 0 if flag else 1
            else:
                return False
            n >>= 1
        return True
