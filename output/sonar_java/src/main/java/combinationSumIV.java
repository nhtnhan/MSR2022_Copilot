/** https://leetcode.com/problems/combination-sum-iv/ */
//Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.
//The answer is guaranteed to fit in a 32-bit integer.

class combinationSumIV {
    public int combinationSum4(int[] nums, int target) {
        if (nums.length == 0 || target < 0) return 0;
        if (target == 0) return 1;
        int[] dp = new int[target + 1];
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < nums.length; j++) {
                if (i >= nums[j]) {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }
}

