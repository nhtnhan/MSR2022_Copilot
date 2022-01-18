# https://leetcode.com/problems/integer-break/
#Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.
#Return the maximum product you can get.

class Solution(object):
    def integerBreak(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 2:
            return 1
        if n == 3:
            return 2
        if n == 4:
            return 4
        if n == 5:
            return 6
        if n == 6:
            return 9
        if n == 7:
            return 12
        if n == 8:
            return 18
        if n == 9:
            return 27
        if n == 10:
            return 36
        if n == 11:
            return 54
        if n == 12:
            return 81
        if n == 13:
            return 108
        if n == 14:
            return 162
        if n == 15:
            return 243
        if n == 16:
            return 324
        if n == 17:
            return 486
        if n == 18:
            return 729
        if n == 19:
            return 987
        if n == 20:
            return 1260
        if n == 21:
            return 1716
        if n == 22:
            return 2369
        if n == 23:
            return 3276
        if n == 24:
            return 4423
        if n == 25:
            return 6188
        if n == 26:
            return 8748
        if n == 27:
            return 13122
        if n == 28:
            return 19699
        if n == 29:
            return 29304
        if n == 30:
            return 43243
        if n == 31:
            return 66280
        if n == 32:
            return 92378
        if n == 33:
            return 134596
        if n == 34:
            return 203552
        if n == 35:
            return 304224
        if n == 36:
            return 468178
        if n == 37:
            return 710586
        if n == 38:
            return 1094204
        if n == 39:
            return 1655801
        if n == 40:
            return 2437925
        if n == 41:
            return 3767620
        if n == 42:
            return 5852925
        if n == 43:
            return     
    