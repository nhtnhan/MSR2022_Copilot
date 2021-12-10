/** https://leetcode.com/problems/can-i-win/ */
//In the "100 game" two players take turns adding, to a running total, any integer from 1 to 10. The player who first causes the running total to reach or exceed 100 wins.
//What if we change the game so that players cannot re-use integers?
//For example, two players might take turns drawing from a common pool of numbers from 1 to 15 without replacement until they reach a total >= 100.
//Given two integers maxChoosableInteger and desiredTotal, return true if the first player to move can force a win, otherwise, return false. Assume both players play optimally.

bool helper(vector<int>& nums, int desiredTotal, int cur, vector<vector<int>>& dp) {
    if (cur >= nums.size()) return false;
    if (dp[cur][desiredTotal] != -1) return dp[cur][desiredTotal];
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > desiredTotal) continue;
        if (nums[i] > 0 && helper(nums, desiredTotal - nums[i], i + 1, dp)) {
            dp[cur][desiredTotal] = true;
            return true;
        }
    }
    dp[cur][desiredTotal] = false;
    return false;
}

bool canIWin(int maxChoosableInteger, int desiredTotal){
    if (desiredTotal <= 0) return true;
    if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) return false;
    if (maxChoosableInteger == 1) return true;
    vector<int> nums;
    for (int i = 1; i <= maxChoosableInteger; i++) {
        nums.push_back(i);
    }
    vector<vector<int>> dp(maxChoosableInteger + 1, vector<int>(desiredTotal + 1, -1));
    return helper(nums, desiredTotal, 0, dp);
}


    