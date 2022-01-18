/** https://leetcode.com/problems/counting-bits/ */
//Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize){
    int *ans = (int *)malloc(sizeof(int) * (n + 1));
    ans[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans[i] = ans[i >> 1] + (i & 1);
    }
    *returnSize = n + 1;
    return ans;
}
    