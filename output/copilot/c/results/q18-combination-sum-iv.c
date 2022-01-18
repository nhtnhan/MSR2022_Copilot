/** https://leetcode.com/problems/combination-sum-iv/ */
//Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.
//The answer is guaranteed to fit in a 32-bit integer.



int combinationSum4(int* nums, int numsSize, int target)
{
    int dp[target + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= target; i++)
    {
        for (int j = 0; j < numsSize; j++)
        {
            if (i - nums[j] >= 0)
            {
                dp[i] += dp[i - nums[j]];
            }
        }
    }
    return dp[target];
}
    