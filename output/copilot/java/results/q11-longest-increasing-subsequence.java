/** https://leetcode.com/problems/longest-increasing-subsequence/ */
//Given an integer array nums, return the length of the longest strictly increasing subsequence.
//A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

class Solution {
    public int lengthOfLIS(int[] nums) {
        if(nums.length == 0) return 0;
        int[] dp = new int[nums.length];
        dp[0] = 1;
        int max = 1;
        for(int i = 1; i < nums.length; i++) {
            int max_val = 0;
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    max_val = Math.max(max_val, dp[j]);
                }
            }
            dp[i] = max_val + 1;
            max = Math.max(max, dp[i]);
        }
        return max;
    }
}