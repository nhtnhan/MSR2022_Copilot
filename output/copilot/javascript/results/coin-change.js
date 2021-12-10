/** https://leetcode.com/problems/coin-change/ */
//You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
//Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
//You may assume that you have an infinite number of each kind of coin.

/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */
 var coinChange = function(coins, amount) {
    if (amount < 0) {
   return -1;
}
if (amount === 0) {
   return 0;
}
if (coins.length === 0) {
   return -1;
}
var min = Infinity;
for (var i = 0; i < coins.length; i++) {
   var result = coinChange(coins.slice(i + 1), amount - coins[i]);
   if (result >= 0 && result < min) {
       min = result + 1;
   }
}
return min === Infinity ? -1 : min;
};
