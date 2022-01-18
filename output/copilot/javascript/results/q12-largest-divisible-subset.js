/** https://leetcode.com/problems/largest-divisible-subset/ */
//Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
//answer[i] % answer[j] == 0, or
//answer[j] % answer[i] == 0
//If there are multiple solutions, return any of them.

/**
 * @param {number[]} nums
 * @return {number[]}
 */
 var largestDivisibleSubset = function(nums) {
    if (nums.length === 0) return [];
nums.sort((a, b) => a - b);
let dp = new Array(nums.length).fill(1);
let prev = new Array(nums.length).fill(-1);
let max = 0;
let maxIndex = 0;
for (let i = 0; i < nums.length; i++) {
   for (let j = 0; j < i; j++) {
       if (nums[i] % nums[j] === 0 && dp[i] < dp[j] + 1) {
           dp[i] = dp[j] + 1;
           prev[i] = j;
       }
   }
   if (dp[i] > max) {
       max = dp[i];
       maxIndex = i;
   }
}
let res = [];
while (maxIndex !== -1) {
   res.unshift(nums[maxIndex]);
   maxIndex = prev[maxIndex];
}
return res;
};
