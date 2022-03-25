# https://leetcode.com/problems/number-of-digit-one/

# count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
class Solution(object):
    def countDigitOne(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 0:
            return 0
        count = 0
        for i in range(1, n + 1):
            count += self.helper(i)
        return count