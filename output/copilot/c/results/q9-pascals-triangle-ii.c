/** https://leetcode.com/problems/pascals-triangle-ii/ */



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
    int* res = (int*)malloc(sizeof(int) * (rowIndex + 1));
    *returnSize = rowIndex + 1;
    res[0] = 1;
    for (int i = 1; i <= rowIndex; i++) {
        res[i] = 1;
        for (int j = i - 1; j > 0; j--) {
            res[j] += res[j - 1];
        }
    }
    return res;
}
    