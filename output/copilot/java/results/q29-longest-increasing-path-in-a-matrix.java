/** https://leetcode.com/problems/longest-increasing-path-in-a-matrix/ */
//Given an m x n integers matrix, return the length of the longest increasing path in matrix.
//From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

class Solution {
    public int longestIncreasingPath(int[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return 0;
        }
        int m = matrix.length;
        int n = matrix[0].length;
        int[][] cache = new int[m][n];
        int max = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                max = Math.max(max, dfs(matrix, i, j, cache));
            }
        }
        return max;
    }
    private int dfs(int[][] matrix, int i, int j, int[][] cache) {
        if (cache[i][j] > 0) {
            return cache[i][j];
        }
        int m = matrix.length;
        int n = matrix[0].length;
        int max = 1;
        if (i > 0 && matrix[i - 1][j] > matrix[i][j]) {
            max = Math.max(max, 1 + dfs(matrix, i - 1, j, cache));
        }
        if (i < m - 1 && matrix[i + 1][j] > matrix[i][j]) {
            max = Math.max(max, 1 + dfs(matrix, i + 1, j, cache));
        }
        if (j > 0 && matrix[i][j - 1] > matrix[i][j]) {
            max = Math.max(max, 1 + dfs(matrix, i, j - 1, cache));
        }
        if (j < n - 1 && matrix[i][j + 1] > matrix[i][j]) {
            max = Math.max(max, 1 + dfs(matrix, i, j + 1, cache));
        }
        cache[i][j] = max;
        return max;
    }
}