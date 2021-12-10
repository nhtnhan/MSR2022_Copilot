# https://leetcode.com/problems/perfect-squares/
#Given an integer n, return the least number of perfect square numbers that sum to n.
#A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

class Solution(object):
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        import math
        dp = [0]
        for i in range(1, n+1):
            dp.append(i)
            for j in range(1, int(math.sqrt(i))+1):
                dp[i] = min(dp[i], dp[i - j**2] + 1)
        return dp[n]