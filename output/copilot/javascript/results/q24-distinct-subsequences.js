/** https://leetcode.com/problems/distinct-subsequences/ */

/**
 * @param {string} s
 * @param {string} t
 * @return {number}
 */
var numDistinct = function(s, t) {
    const dp = [];
    for (let i = 0; i <= s.length; i++) {
        dp[i] = [];
        for (let j = 0; j <= t.length; j++) {
        if (i === 0) {
            dp[i][j] = j;
        } else if (j === 0) {
            dp[i][j] = 1;
        } else {
            dp[i][j] = dp[i - 1][j];
            if (s[i - 1] === t[j - 1]) {
            dp[i][j] += dp[i - 1][j - 1];
            }
        }
        }
    }
    return dp[s.length][t.length];   
};