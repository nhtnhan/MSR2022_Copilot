/** https://leetcode.com/problems/integer-replacement/ */
//Given a positive integer n, you can apply one of the following operations:
//If n is even, replace n with n / 2.
//If n is odd, replace n with either n + 1 or n - 1.
//Return the minimum number of operations needed for n to become 1.

/**
 * @param {number} n
 * @return {number}
 */
 var integerReplacement = function(n) {
    if(n === 1) return 0;
if(n === 2) return 1;
if(n === 3) return 2;
if(n % 2 === 0) return 1 + integerReplacement(n / 2);
if(n % 2 !== 0 && n % 3 === 0) return 1 + integerReplacement(n / 3);
if(n % 2 !== 0 && n % 3 !== 0) return 2 + integerReplacement(n - 1);
}
