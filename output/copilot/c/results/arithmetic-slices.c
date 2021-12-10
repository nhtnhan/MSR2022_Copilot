/** https://leetcode.com/problems/arithmetic-slices/ */
//An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
//For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
//Given an integer array nums, return the number of arithmetic subarrays of nums.
//A subarray is a contiguous subsequence of the array.



int numberOfArithmeticSlices(int* nums, int numsSize){
    int i, j, k, count = 0;
    for (i = 0; i < numsSize - 2; i++) {
        for (j = i + 2; j < numsSize; j++) {
            if (nums[j] - nums[j - 1] == nums[j - 1] - nums[j - 2]) {
                count++;
            }
        }
    }
    return count;
}
    