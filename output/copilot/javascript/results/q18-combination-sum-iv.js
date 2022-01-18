/** https://leetcode.com/problems/combination-sum-iv/ */
//Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.
//The answer is guaranteed to fit in a 32-bit integer.

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
 var combinationSum4 = function(nums, target) {
    if (nums.length === 0) return 0;
let dp = [];
dp[0] = 1;
for (let i = 1; i <= target; i++) {
   for (let j = 0; j < nums.length; j++) {
       if (i - nums[j] >= 0) {
           dp[i] += dp[i - nums[j]];
       }
   }
}
return dp[target];
}
