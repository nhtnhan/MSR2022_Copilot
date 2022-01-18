/** https://leetcode.com/problems/burst-balloons/ */
//You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.
//If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.
//Return the maximum coins you can collect by bursting the balloons wisely.



int maxCoins(int* nums, int numsSize){
    int *nums_copy = (int*)malloc(sizeof(int) * numsSize);
    memcpy(nums_copy, nums, sizeof(int) * numsSize);
    int *dp = (int*)malloc(sizeof(int) * (numsSize + 2));
    memset(dp, 0, sizeof(int) * (numsSize + 2));
    dp[0] = 1;
    dp[numsSize + 1] = 1;
    for(int i = 1; i <= numsSize; i++){
        dp[i] = nums_copy[i - 1];
    }
    for(int i = 1; i <= numsSize; i++){
        for(int j = 1; j <= numsSize; j++){
            int left = i - 1;
            int right = j + 1;
            while(left >= 1 && right <= numsSize){
                dp[i] = max(dp[i], dp[left] * dp[right] * nums_copy[i - 1]);
                left--;
                right++;
            }
        }
    }
    return dp[numsSize];
}
    