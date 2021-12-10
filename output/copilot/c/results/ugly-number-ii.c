/** https://leetcode.com/problems/ugly-number-ii/ */

/**
 * An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
 * Given an integer n, return the nth ugly number.
 */
int nthUglyNumber(int n){
    int ugly[n];
    ugly[0] = 1;
    int i2 = 0, i3 = 0, i5 = 0;
    for(int i = 1; i < n; i++){
        ugly[i] = min(min(ugly[i2] * 2, ugly[i3] * 3), ugly[i5] * 5);
        if(ugly[i] == ugly[i2] * 2) i2++;
        if(ugly[i] == ugly[i3] * 3) i3++;
        if(ugly[i] == ugly[i5] * 5) i5++;
    }
    return ugly[n - 1];
}
    