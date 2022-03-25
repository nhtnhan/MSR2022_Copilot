/** https://leetcode.com/problems/longest-increasing-subsequence/ */
//Given an integer array nums, return the length of the longest strictly increasing subsequence.
//A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].



int lengthOfLIS(int* nums, int numsSize){
    if(numsSize == 0) return 0;
    int dp[numsSize];
    memset(dp, 0, sizeof(dp));
    int max = 1;
    dp[0] = 1;
    for(int i = 1; i < numsSize; i++){
        int max_num = 0;
        for(int j = 0; j < i; j++){
            if(nums[i] > nums[j]){
                max_num = max_num > dp[j] ? max_num : dp[j];
            }
        }
        dp[i] = max_num + 1;
        max = max > dp[i] ? max : dp[i];
    }
    return max;
}
    