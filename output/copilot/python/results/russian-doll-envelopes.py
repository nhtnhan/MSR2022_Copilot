# https://leetcode.com/problems/russian-doll-envelops/
#You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.
#One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.
#Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).
#Note: You cannot rotate an envelope.

class Solution(object):
    def maxEnvelopes(self, envelopes):
        """
        :type envelopes: List[List[int]]
        :rtype: int
        """
        if not envelopes:
            return 0
        envelopes.sort(key=lambda x: (x[0], -x[1]))
        dp = [1] * len(envelopes)
        for i in range(1, len(envelopes)):
            for j in range(i):
                if envelopes[i][0] > envelopes[j][0] and envelopes[i][1] > envelopes[j][1]:
                    dp[i] = max(dp[i], dp[j] + 1)
        return max(dp)