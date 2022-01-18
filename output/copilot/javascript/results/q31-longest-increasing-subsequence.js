/** https://leetcode.com/problems/longest-increasing-subsequence/ */
//Given an integer array nums, return the length of the longest strictly increasing subsequence.
//A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

/**
 * @param {number[]} nums
 * @return {number}
 */
 var lengthOfLIS = function(nums) {
    if(!nums || nums.length === 0) return 0;
let dp = [nums[0]];
for(let i = 1; i < nums.length; i++){
   if(nums[i] > dp[dp.length - 1]){
       dp.push(nums[i]);
   }else{
       let index = binarySearch(dp, nums[i]);
       dp[index] = nums[i];
   }
}
return dp.length;
};
