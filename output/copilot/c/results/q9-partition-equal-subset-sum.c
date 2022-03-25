/** https://leetcode.com/problems/partition-equal-subset-sum/ */
//Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.



bool canPartition(int* nums, int numsSize){
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    if (sum % 2 != 0) {
        return false;
    }
    int target = sum / 2;
    bool dp[numsSize][target + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < numsSize; i++) {
        dp[i][0] = true;
    }
    for (int i = 1; i <= target; i++) {
        dp[0][i] = (nums[0] == i);
    }
    for (int i = 1; i < numsSize; i++) {
        for (int j = 1; j <= target; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= nums[i]) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i]];
            }
        }
    }
    return dp[numsSize - 1][target];
}
    