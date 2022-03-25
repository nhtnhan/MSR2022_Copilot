/** https://leetcode.com/problems/rotate-function/ */
//You are given an integer array nums of length n.
//Assume arrk to be an array obtained by rotating nums by k positions clock-wise. We define the rotation function F on nums as follow:
//F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1].
//Return the maximum value of F(0), F(1), ..., F(n-1).
//The test cases are generated so that the answer fits in a 32-bit integer.

/**
 * @param {number[]} nums
 * @return {number}
 */
 var maxRotateFunction = function(nums) {
    let sum = 0;
let max = 0;
for(let i = 0; i < nums.length; i++) {
   sum += nums[i];
   max += nums[i] * i;
}
let cur = max;
for(let i = nums.length - 1; i >= 1; i--) {
   cur = cur + sum - nums.length * nums[i];
   max = Math.max(max, cur);
}
return max;
}
