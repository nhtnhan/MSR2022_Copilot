# https://leetcode.com/problems/partition-equal-subset-sum/
#Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

class Solution(object):
    def canPartition(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        n = len(nums)
        if n == 0:
            return False
        if n == 1:
            return True
        sum_nums = sum(nums)
        if sum_nums % 2 != 0:
            return False

        target = sum_nums / 2
        dp = [False] * (target + 1)
        dp[0] = True
        for i in range(n):
            for j in range(target, nums[i]-1, -1):
                dp[j] = dp[j] | dp[j - nums[i]]
        return dp[target]    
    