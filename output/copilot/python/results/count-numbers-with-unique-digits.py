# https://leetcode.com/problems/count-numbers-with-unique-digits/
#Given an integer n, return the count of all numbers with unique digits, x, where 0 <= x < 10n.

class Solution(object):
    def countNumbersWithUniqueDigits(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 0:
            return 1
        if n == 1:
            return 10
        if n > 10:
            return 0
        if n == 2:
            return 9 * 9
        if n == 3:
            return 9 * 9 * 8
        if n == 4:
            return 9 * 9 * 8 * 7
        if n == 5:
            return 9 * 9 * 8 * 7 * 6
        if n == 6:
            return 9 * 9 * 8 * 7 * 6 * 5
        if n == 7:
            return 9 * 9 * 8 * 7 * 6 * 5 * 4
        if n == 8:
            return 9 * 9 * 8 * 7 * 6 * 5 * 4 * 3
        if n == 9:
            return 9 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2