/** https://leetcode.com/problems/longest-increasing-path-in-a-matrix/ */
//Given an m x n integers matrix, return the length of the longest increasing path in matrix.
//From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).



int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize){
    if (matrixSize == 0 || matrixColSize == 0) {
        return 0;
    }
    int **dp = (int **)malloc(sizeof(int *) * matrixSize);
    for (int i = 0; i < matrixSize; i++) {
        dp[i] = (int *)malloc(sizeof(int) * matrixColSize[i]);
    }
    int max = 1;
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[i]; j++) {
            dp[i][j] = 1;
        }
    }
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[i]; j++) {
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x >= 0 && x < matrixSize && y >= 0 && y < matrixColSize[i] && matrix[x][y] > matrix[i][j]) {
                    dp[i][j] = max(dp[i][j], dp[x][y] + 1);
                }
            }
            max = max(max, dp[i][j]);
        }
    }
    return max;
    
}
    