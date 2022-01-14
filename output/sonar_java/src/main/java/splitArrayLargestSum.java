/** https://leetcode.com/problems/split-array-largest-sum/ */
//Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.
//Write an algorithm to minimize the largest sum among these m subarrays.

class splitArrayLargestSum {
    public int splitArray(int[] nums, int m) {
        int n = nums.length;
        int[] sums = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        int[][] dp = new int[m + 1][n + 1];
        for (int i = 1; i <= n; i++) {
            dp[1][i] = sums[i];
        }
        for (int i = 2; i <= m; i++) {
            for (int j = i; j <= n; j++) {
                dp[i][j] = Integer.MAX_VALUE;
                for (int k = i - 1; k < j; k++) {
                    dp[i][j] = Math.min(dp[i][j], Math.max(dp[i - 1][k], sums[j] - sums[k]));
                }
            }
        }
        return dp[m][n];
    }
}
