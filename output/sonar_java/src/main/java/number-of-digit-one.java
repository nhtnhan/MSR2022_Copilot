/** https://leetcode.com/problems/number-of-digit-one/ */

/**
 * Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
 */
class digitOne {
    public int countDigitOne(int n) {
        int res = 0;
        for (long m = 1; m <= n; m *= 10) {
            long a = n / m, b = n % m;
            res += (a + 8) / 10 * m + (a % 10 == 1 ? b + 1 : 0);
        }
        return res;
    }
}