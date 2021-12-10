/** https://leetcode.com/problems/split-array-largest-sum/ */
//Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.
//Write an algorithm to minimize the largest sum among these m subarrays.



int splitArray(int* nums, int numsSize, int m){
    int max = 0, sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        max = max > nums[i] ? max : nums[i];
    }
    if (m == 1) return sum;
    int l = max, r = sum;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (check(nums, numsSize, mid, m)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

bool check(int* nums, int numsSize, int mid, int m) {
    int cur = 0;
    int count = 1;
    for (int i = 0; i < numsSize; i++) {
        if (cur + nums[i] > mid) {
            count++;
            cur = nums[i];
        } else {
            cur += nums[i];
        }
        if (count > m) return false;
    }
    return true;
}
    