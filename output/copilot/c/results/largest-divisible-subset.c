/** https://leetcode.com/problems/largest-divisible-subset/ */
//Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
//answer[i] % answer[j] == 0, or
//answer[j] % answer[i] == 0
//If there are multiple solutions, return any of them.



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* largestDivisibleSubset(int* nums, int numsSize, int* returnSize){
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    if (numsSize == 1) {
        *returnSize = 1;
        int* result = (int*)malloc(sizeof(int) * 1);
        result[0] = nums[0];
        return result;
    }
    int* dp = (int*)malloc(sizeof(int) * numsSize);
    int* index = (int*)malloc(sizeof(int) * numsSize);
    int max = 0;
    int maxIndex = 0;
    for (int i = 0; i < numsSize; i++) {
        dp[i] = 1;
        index[i] = 0;
        for (int j = 0; j < i; j++) {
            if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                index[i] = j;
            }
        }
        if (dp[i] > max) {
            max = dp[i];
            maxIndex = i;
        }
    }
    int* result = (int*)malloc(sizeof(int) * max);
    int currIndex = maxIndex;
    for (int i = max - 1; i >= 0; i--) {
        result[i] = nums[currIndex];
        currIndex = index[currIndex];
    }
    *returnSize = max;
    return result;
}
    