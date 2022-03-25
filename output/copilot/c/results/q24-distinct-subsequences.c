/** https://leetcode.com/problems/distinct-subsequences/ */



int numDistinct(char * s, char * t){
    int s_len = strlen(s);
    int t_len = strlen(t);
    int dp[s_len + 1][t_len + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= s_len; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= s_len; i++) {
        for (int j = 1; j <= t_len; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[s_len][t_len];

}
    