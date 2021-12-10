/** https://leetcode.com/problems/partition-equal-subset-sum/ */
//Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

/**
 * @param {number[]} nums
 * @return {boolean}
 */
 var canPartition = function(nums) {
    var sum = 0;
for (var i = 0; i < nums.length; i++) {
   sum += nums[i];
}
if (sum % 2 != 0) {
   return false;
}
var target = sum / 2;
var dp = [];
for (var i = 0; i < nums.length; i++) {
   dp[i] = [];
   for (var j = 0; j <= target; j++) {
       dp[i][j] = false;
   }
}
for (var i = 0; i < nums.length; i++) {
   dp[i][0] = true;
}
for (var i = 0; i < nums.length; i++) {
   for (var j = 1; j <= target; j++) {
       if (j - nums[i] >= 0) {
           dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
       } else {
           dp[i][j] = dp[i - 1][j];
       }
   }
}
return dp[nums.length - 1][target];
};
