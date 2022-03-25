/** https://leetcode.com/problems/count-numbers-with-unique-digits/ */
//Given an integer n, return the count of all numbers with unique digits, x, where 0 <= x < 10n.

class Solution {
    public int countNumbersWithUniqueDigits(int n) {
        int[] dp = new int[n + 1];
        dp[0] = 1;
        dp[1] = 10;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] * (11 - i);
        }
        int ans = dp[n];
        for (int i = 1; i <= 9; i++) {
            ans += dp[n - 1];
        }
        return ans;
    }
}
    