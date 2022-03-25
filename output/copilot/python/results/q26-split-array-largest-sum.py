# https://leetcode.com/problems/split-array-largest-sum/
#Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.
#Write an algorithm to minimize the largest sum among these m subarrays.

class Solution(object):
    def splitArray(self, nums, m):
        """
        :type nums: List[int]
        :type m: int
        :rtype: int
        """
        if len(nums) < m:
            return 0
        if m == 1:
            return max(nums)
        if m == len(nums):
            return sum(nums)
        left = max(nums)
        right = sum(nums)
        while left <= right:
            mid = (left + right) // 2
            if self.canSplit(nums, m, mid):
                right = mid - 1
            else:
                left = mid + 1
        return left