# https://leetcode.com/problems/largest-divisible-subset/
#Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
#answer[i] % answer[j] == 0, or
#answer[j] % answer[i] == 0
#If there are multiple solutions, return any of them.

class Solution(object):
    def largestDivisibleSubset(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        if len(nums) == 0:
            return []
        nums.sort()
        dp = [1] * len(nums)
        parent = [0] * len(nums)
        max_index = 0
        for i in range(1, len(nums)):
            for j in range(i):
                if nums[i] % nums[j] == 0:
                    if dp[i] < dp[j] + 1:
                        dp[i] = dp[j] + 1
                        parent[i] = j
            if dp[i] > dp[max_index]:
                max_index = i
        result = []
        while max_index != 0:
            result.append(nums[max_index])
            max_index = parent[max_index]
        result.append(nums[max_index])
        return result