# https://leetcode.com/problems/wiggle-subsequence/
#A wiggle sequence is a sequence where the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences.
#For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences (6, -3, 5, -7, 3) alternate between positive and negative.
#In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences. The first is not because its first two differences are positive, and the second is not because its last difference is zero.
#A subsequence is obtained by deleting some elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.
#Given an integer array nums, return the length of the longest wiggle subsequence of nums.

class Solution(object):
    def wiggleMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) < 2:
            return len(nums)
        up = [nums[0]]
        down = [nums[0]]
        for i in range(1, len(nums)):
            if nums[i] > up[-1]:
                up.append(nums[i])
                down.append(nums[i])
            elif nums[i] < down[-1]:
                up.append(nums[i])
                down.append(nums[i])
            else:
                up.append(nums[i])
                down.append(nums[i])
        return max(len(up), len(down))