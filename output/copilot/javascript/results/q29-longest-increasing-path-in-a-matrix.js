/** https://leetcode.com/problems/longest-increasing-path-in-a-matrix/ */
//Given an m x n integers matrix, return the length of the longest increasing path in matrix.
//From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

/**
 * @param {number[][]} matrix
 * @return {number}
 */
 var longestIncreasingPath = function(matrix) {
    if(matrix.length == 0) return 0;
var max = 0;
for(var i = 0; i < matrix.length; i++){
   for(var j = 0; j < matrix[i].length; j++){
       max = Math.max(max, dfs(i, j, matrix));
   }
}
return max;
};
