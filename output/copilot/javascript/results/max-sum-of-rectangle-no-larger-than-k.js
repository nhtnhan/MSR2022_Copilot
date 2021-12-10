/** https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/ */
//Given an m x n matrix matrix and an integer k, return the max sum of a rectangle in the matrix such that its sum is no larger than k.

/**
 * @param {number[][]} matrix
 * @param {number} k
 * @return {number}
 */
 var maxSumSubmatrix = function(matrix, k) {
    let max = Number.NEGATIVE_INFINITY;
        for (let i = 0; i < matrix.length; i++) {
        for (let j = 0; j < matrix[0].length; j++) {
            let sum = 0;
            for (let x = i; x < matrix.length; x++) {
                for (let y = j; y < matrix[0].length; y++) {
                    sum += matrix[x][y];
                    if (sum > max && sum <= k) {
                        max = sum;
                    }
                }
            }
        }
    }
    return max;
}
