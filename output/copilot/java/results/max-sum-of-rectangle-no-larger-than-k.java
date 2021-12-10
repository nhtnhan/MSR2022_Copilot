/** https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/ */
//Given an m x n matrix matrix and an integer k, return the max sum of a rectangle in the matrix such that its sum is no larger than k.

class Solution {
    public int maxSumSubmatrix(int[][] matrix, int k) {
        int m = matrix.length;
        if(m == 0) return 0;
        int n = matrix[0].length;
        if(n == 0) return 0;
        int max = Integer.MIN_VALUE;
        for(int i = 0; i < m; i++) {
            int[] row = matrix[i];
            for(int j = 0; j < n; j++) {
                for(int l = i; l < m; l++) {
                    int[] row2 = matrix[l];
                    int sum = 0;
                    for(int r = j; r < n; r++) {
                        sum += row2[r];
                        if(sum > k) break;
                        if(sum > max) max = sum;
                    }
                }
            }
        }
        return max;
    }
}
    