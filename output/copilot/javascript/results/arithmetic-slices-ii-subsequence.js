/** https://leetcode.com/problems/arithmetic-slices-ii-subsequence/ */
//Given an integer array nums, return the number of all the arithmetic subsequences of nums.
//A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
//For example, [1, 3, 5, 7, 9], [7, 7, 7, 7], and [3, -1, -5, -9] are arithmetic sequences.
//For example, [1, 1, 2, 5, 7] is not an arithmetic sequence.
//A subsequence of an array is a sequence that can be formed by removing some elements (possibly none) of the array.
//For example, [2,5,10] is a subsequence of [1,2,1,2,4,1,5,10].
//The test cases are generated so that the answer fits in 32-bit integer.

/**
 * @param {number[]} nums
 * @return {number}
 */
 var numberOfArithmeticSlices = function(nums) {
    var len = nums.length;
if (len < 3) return 0;
var dp = new Array(len);
for (var i = 0; i < len; i++) {
   dp[i] = new Array(len);
   dp[i][i] = 1;
}
for (var i = len - 2; i >= 0; i--) {
   for (var j = i + 1; j < len; j++) {
       if (nums[j] - nums[i] == nums[j + 1] - nums[i + 1]) {
           dp[i][j] = dp[i + 1][j - 1] + 2;
       } else {
           dp[i][j] = dp[i + 1][j];
       }
   }
}
var sum = 0;
for (var i = 0; i < len; i++) {
   sum += dp[0][i];
}
return sum - len;
};
