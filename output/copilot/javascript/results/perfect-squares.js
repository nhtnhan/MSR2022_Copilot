/** https://leetcode.com/problems/perfect-squares/ */
//Given an integer n, return the least number of perfect square numbers that sum to n.
//A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

/**
 * @param {number} n
 * @return {number}
 */
 var numSquares = function(n) {
    var squares = [],
   i = 0;
while(Math.pow(i, 2) <= n) {
   squares.push(Math.pow(i, 2));
   i++;
}
var dp = new Array(n + 1).fill(Infinity);
dp[0] = 0;
for(var i = 1; i <= n; i++) {
   for(var j = 0; j < squares.length; j++) {
       if(squares[j] <= i) {
           dp[i] = Math.min(dp[i], dp[i - squares[j]] + 1);
       }
   }
}
return dp[n];
};
