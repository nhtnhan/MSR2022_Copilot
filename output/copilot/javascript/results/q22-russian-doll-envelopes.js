/** https://leetcode.com/problems/russian-doll-envelops/ */
//You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.
//One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.
//Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).
//Note: You cannot rotate an envelope.

/**
 * @param {number[][]} envelopes
 * @return {number}
 */
 var maxEnvelopes = function(envelopes) {
    if (envelopes.length === 0) {
   return 0;
}
envelopes.sort((a, b) => {
   if (a[0] === b[0]) {
       return b[1] - a[1];
   }
   return a[0] - b[0];
});
let dp = new Array(envelopes.length);
dp[0] = 1;
let max = 1;
for (let i = 1; i < envelopes.length; i++) {
   dp[i] = 1;
   for (let j = 0; j < i; j++) {
       if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
           dp[i] = Math.max(dp[i], dp[j] + 1);
       }
   }
   max = Math.max(max, dp[i]);
}
return max;
};
