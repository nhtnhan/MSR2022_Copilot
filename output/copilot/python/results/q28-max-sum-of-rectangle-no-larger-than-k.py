# https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/
#Given an m x n matrix matrix and an integer k, return the max sum of a rectangle in the matrix such that its sum is no larger than k.

class Solution(object):
    def maxSumSubmatrix(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        if not matrix or not matrix[0]:
            return 0
        n, m = len(matrix), len(matrix[0])
        max_sum = 0
        for i in range(n):
            for j in range(i, n):
                sum_list = [0 for _ in range(m)]
                for k in range(j + 1):
                    for l in range(m):
                        sum_list[l] += matrix[k][l]
                    sum_max = max(sum_list)
                    if sum_max <= k:
                        max_sum = max(max_sum, sum_max)
        return max_sum
    