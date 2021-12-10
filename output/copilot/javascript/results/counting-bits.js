/** https://leetcode.com/problems/counting-bits/ */
//Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

/**
 * @param {number} n
 * @return {number[]}
 */
 var countBits = function(n) {
    var ans = [];
ans[0] = 0;
for(var i = 1; i <= n; i++){
   ans[i] = ans[i >> 1] + (i & 1);
}
return ans;
};
