/** https://leetcode.com/problems/longest-increasing-subsequence/ */
//You are given an array prices where prices[i] is the price of a given stock on the ith day.
//Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
//After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
//Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



int maxProfit(int* prices, int pricesSize){
    int maxProfit = 0;
    int minPrice = INT_MAX;
    int i;
    for(i = 0; i < pricesSize; i++){
        if(prices[i] < minPrice){
            minPrice = prices[i];
        }
        if(prices[i] - minPrice > maxProfit){
            maxProfit = prices[i] - minPrice;
        }
    }
    return maxProfit;
}
    