/** https://leetcode.com/problems/integer-replacement/ */
//Given a positive integer n, you can apply one of the following operations:
//If n is even, replace n with n / 2.
//If n is odd, replace n with either n + 1 or n - 1.
//Return the minimum number of operations needed for n to become 1.

class Solution {
    public int integerReplacement(int n) {
        if (n == 1)
            return 0;
        if (n % 2 == 0)
            return 1 + integerReplacement(n / 2);
        else
            return 1 + Math.min(integerReplacement(n + 1), integerReplacement(n - 1));
    }
}
    