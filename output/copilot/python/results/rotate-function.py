# https://leetcode.com/problems/rotate-function/
#You are given an integer array nums of length n.
#Assume arrk to be an array obtained by rotating nums by k positions clock-wise. We define the rotation function F on nums as follow:
#F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1].
#Return the maximum value of F(0), F(1), ..., F(n-1).
#The test cases are generated so that the answer fits in a 32-bit integer.

class Solution(object):
    def maxRotateFunction(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        if len(nums) == 1:
            return nums[0]
        sum_nums = sum(nums)
        sum_of_index = sum([i * nums[i] for i in range(len(nums))])
        max_sum_of_index = sum_of_index
        for i in range(1, len(nums)):
            sum_of_index = sum_of_index + sum_nums - len(nums) * nums[-i]
            max_sum_of_index = max(max_sum_of_index, sum_of_index)
        return max_sum_of_index