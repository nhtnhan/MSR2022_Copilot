/** https://leetcode.com/problems/longest-increasing-subsequence/ */
//You are given an array prices where prices[i] is the price of a given stock on the ith day.
//Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
//After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
//Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

/**
 * @param {number[]} prices
 * @return {number}
 */
 var maxProfit = function(prices) {
    var profit = 0;
for (var i = 1; i < prices.length; i++) {
   if (prices[i] > prices[i-1]) {
       profit += (prices[i] - prices[i-1]);
   }
}
return profit;
};
