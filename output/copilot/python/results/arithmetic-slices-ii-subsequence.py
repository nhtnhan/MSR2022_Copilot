# https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
#Given an integer array nums, return the number of all the arithmetic subsequences of nums.
#A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
#For example, [1, 3, 5, 7, 9], [7, 7, 7, 7], and [3, -1, -5, -9] are arithmetic sequences.
#For example, [1, 1, 2, 5, 7] is not an arithmetic sequence.
#A subsequence of an array is a sequence that can be formed by removing some elements (possibly none) of the array.
#For example, [2,5,10] is a subsequence of [1,2,1,2,4,1,5,10].
#The test cases are generated so that the answer fits in 32-bit integer.

class Solution(object):
    def numberOfArithmeticSlices(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n < 3:
            return 0
        dp = [0] * n
        for i in range(2, n):
            if nums[i] - nums[i-1] == nums[i-1] - nums[i-2]:
                dp[i] = dp[i-1] + 1
        return sum(dp)