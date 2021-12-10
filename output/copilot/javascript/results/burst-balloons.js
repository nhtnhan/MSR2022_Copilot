/** https://leetcode.com/problems/burst-balloons/ */
//You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.
//If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.
//Return the maximum coins you can collect by bursting the balloons wisely.

/**
 * @param {number[]} nums
 * @return {number}
 */
 var maxCoins = function(nums) {
    var balloons = nums.map(function(n){ return n ? n : 1; });
//console.log(balloons);
var max = 0;
for (var i = 0; i < balloons.length; i++) {
   for (var j = i + 1; j < balloons.length; j++) {
       for (var k = j + 1; k < balloons.length; k++) {
           var val = balloons[i - 1] * balloons[i] * balloons[j] * balloons[k];
           max = Math.max(max, val);
       }
   }
}
return max;
};
