# https://leetcode.com/problems/distinct-subsequences/

class Solution(object):
    def numDistinct(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """ 
        s_len = len(s)
        t_len = len(t)
        dp = [[0]*(s_len+1) for _ in range(t_len+1)]
        for i in range(s_len+1):
            dp[0][i] = 1
        for i in range(1, t_len+1):
            for j in range(1, s_len+1):
                dp[i][j] = dp[i][j-1]
                if s[j-1] == t[i-1]:
                    dp[i][j] += dp[i-1][j-1]
        return dp[-1][-1]
    