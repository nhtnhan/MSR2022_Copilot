/** https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/ */
//Given an m x n matrix matrix and an integer k, return the max sum of a rectangle in the matrix such that its sum is no larger than k.



int maxSumSubmatrix(int** matrix, int matrixSize, int* matrixColSize, int k){
    int i, j, m, n, sum, max = INT_MIN;
    for(i = 0; i < matrixSize; i++){
        for(j = i; j < matrixSize; j++){
            sum = 0;
            for(m = 0; m < matrixSize; m++){
                for(n = 0; n < matrixColSize[m]; n++){
                    sum += matrix[m][n];
                }
            }
            if(sum <= k){
                max = max > sum ? max : sum;
            }
        }
    }
    return max;
}
    