/** https://leetcode.com/problems/super-ugly-number/ */
//A super ugly number is a positive integer whose prime factors are in the array primes.
//Given an integer n and an array of integers primes, return the nth super ugly number.
//The nth super ugly number is guaranteed to fit in a 32-bit signed integer.

/**
 * @param {number} n
 * @param {number[]} primes
 * @return {number}
 */
 var nthSuperUglyNumber = function(n, primes) {
    let ugly = [1];
let index = [0];
for(let i = 1; i < n; i++) {
   let min = Number.MAX_SAFE_INTEGER;
   let minIndex = -1;
   for(let j = 0; j < primes.length; j++) {
       let temp = ugly[index[j]] * primes[j];
       if(temp < min) {
           min = temp;
           minIndex = j;
       }
   }
   ugly[i] = min;
   index[minIndex]++;
}
return ugly[n-1]; 
};
