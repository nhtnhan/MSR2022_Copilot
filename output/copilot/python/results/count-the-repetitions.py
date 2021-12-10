# https://leetcode.com/problems/count-the-repetitions/
#We define str = [s, n] as the string str which consists of the string s concatenated n times.
#For example, str == ["abc", 3] =="abcabcabc".
#We define that string s1 can be obtained from string s2 if we can remove some characters from s2 such that it becomes s1.
#For example, s1 = "abc" can be obtained from s2 = "abdbec" based on our definition by removing the bolded underlined characters.
#You are given two strings s1 and s2 and two integers n1 and n2. You have the two strings str1 = [s1, n1] and str2 = [s2, n2].
#Return the maximum integer m such that str = [str2, m] can be obtained from str1.

class Solution(object):
    def getMaxRepetitions(self, s1, n1, s2, n2):
        """
        :type s1: str
        :type n1: int
        :type s2: str
        :type n2: int
        :rtype: int
        """
        count = 0
        s1_idx = 0
        s2_idx = 0
        while count < n1:
            if s1[s1_idx] == s2[s2_idx]:
                s2_idx += 1
                if s2_idx == n2:
                    s2_idx = 0
                    count += 1
            s1_idx += 1
            if s1_idx == n1:
                s1_idx = 0
        return count % n2