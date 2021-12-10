# https://leetcode.com/problems/unique-substrings-in-wraparound-string/
#We define the string s to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", so s will look like this:
#"...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
#Given a string p, return the number of unique non-empty substrings of p are present in s.

class Solution(object):
    def findSubstringInWraproundString(self, p):
        """
        :type p: str
        :rtype: int
        """
        if not p:
            return 0
        d = {}
        for i in range(len(p)):
            if i == 0:
                d[p[i]] = 1
            else:
                if ord(p[i]) - ord(p[i - 1]) == 1 or ord(p[i]) - ord(p[i - 1]) == -25:
                    d[p[i]] = d[p[i - 1]] + 1
                else:
                    d[p[i]] = 1
        return sum(d.values())    
    