/** https://leetcode.com/problems/arithmetic-slices/ */
//An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
//For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
//Given an integer array nums, return the number of arithmetic subarrays of nums.
//A subarray is a contiguous subsequence of the array.

/**
 * @param {number[]} nums
 * @return {number}
 */
 var numberOfArithmeticSlices = function(nums) {
    let count = 0;
const dp = [];
for (let i = 0; i < nums.length; i++) {
   dp[i] = [];
   for (let j = 0; j <= i; j++) {
       if (j === i) {
           dp[i][j] = 1;
       } else if (j === i - 1) {
           dp[i][j] = 1;
       } else {
           dp[i][j] = dp[i - 1][j] + dp[i - 1][j + 1];
       }
   }
   count += dp[i][0];
}
return count;
};
