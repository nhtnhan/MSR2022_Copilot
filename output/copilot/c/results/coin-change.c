/** https://leetcode.com/problems/coin-change/ */
//You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
//Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
//You may assume that you have an infinite number of each kind of coin.



int coinChange(int* coins, int coinsSize, int amount){
    int *dp = malloc(sizeof(int) * (amount + 1));
    memset(dp, 0, sizeof(int) * (amount + 1));
    dp[0] = 0;
    for(int i = 1; i <= amount; i++){
        dp[i] = INT_MAX;
        for(int j = 0; j < coinsSize; j++){
            if(i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX){
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    int result = dp[amount];
    free(dp);
    return result == INT_MAX ? -1 : result;
}
    