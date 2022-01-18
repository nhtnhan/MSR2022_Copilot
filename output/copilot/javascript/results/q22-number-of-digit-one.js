/** https://leetcode.com/problems/number-of-digit-one/ */

/**
 * Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
 */
/**
 * @param {number} n
 * @return {number}
 */
 var countDigitOne = function(n) {
    let count = 0;
for (let i = 1; i <= n; i++) {
   let num = i;
   while (num > 0) {
       if (num % 10 === 1) {
           count++;
       }
       num = Math.floor(num / 10);
   }
}
return count;
};
