/** https://leetcode.com/problems/split-array-largest-sum/ */
//Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.
//Write an algorithm to minimize the largest sum among these m subarrays.

/**
 * @param {number[]} nums
 * @param {number} m
 * @return {number}
 */
 var splitArray = function(nums, m) {
    let max = 0;
for (let i = 0; i < nums.length; i++) {
   max = Math.max(max, nums[i]);
}
let l = max;
let r = max * nums.length;
while (l < r) {
   let mid = Math.floor((l + r) / 2);
   if (canSplit(nums, m, mid)) {
       r = mid;
   } else {
       l = mid + 1;
   }
}
return l;
}
