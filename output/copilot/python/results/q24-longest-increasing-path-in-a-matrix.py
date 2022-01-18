# https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
#Given an m x n integers matrix, return the length of the longest increasing path in matrix.
#From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

class Solution(object):
    def longestIncreasingPath(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        if not matrix or not matrix[0]:
            return 0
        m, n = len(matrix), len(matrix[0])
        dp = [[0] * n for _ in range(m)]
        res = 0
        for i in range(m):
            for j in range(n):
                self.dfs(matrix, i, j, m, n, dp)
                res = max(res, dp[i][j])
        return res