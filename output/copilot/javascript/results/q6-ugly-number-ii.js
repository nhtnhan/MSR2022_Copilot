/** https://leetcode.com/problems/ugly-number-ii/ */

/**
 * An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
 * Given an integer n, return the nth ugly number.
 */
/**
 * @param {number} n
 * @return {number}
 */
 var nthUglyNumber = function(n) {
    if (n <= 0) return 0;
if (n === 1) return 1;
var i2 = 0, i3 = 0, i5 = 0;
var arr = [1];
var next2 = 2, next3 = 3, next5 = 5;
for (var i = 1; i < n; i++) {
   var min = Math.min(next2, next3, next5);
   arr.push(min);
   if (min === next2) {
       i2++;
       next2 = arr[i2] * 2;
   }
   if (min === next3) {
       i3++;
       next3 = arr[i3] * 3;
   }
   if (min === next5) {
       i5++;
       next5 = arr[i5] * 5;
   }
}
return arr[n - 1];
};
