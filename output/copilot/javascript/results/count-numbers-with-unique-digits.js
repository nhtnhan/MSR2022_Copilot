/** https://leetcode.com/problems/count-numbers-with-unique-digits/ */
//Given an integer n, return the count of all numbers with unique digits, x, where 0 <= x < 10n.

/**
 * @param {number} n
 * @return {number}
 */
 var countNumbersWithUniqueDigits = function(n) {
    if (n === 0) {
   return 1;
}
if (n === 1) {
   return 10;
}
let result = 10;
let num = 9;
let count = 9;
while (n > 1) {
   count *= num;
   result += count;
   num--;
   n--;
}
return result;
};
