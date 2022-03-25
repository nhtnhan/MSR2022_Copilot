/** https://leetcode.com/problems/count-the-repetitions/ */
//We define str = [s, n] as the string str which consists of the string s concatenated n times.
//For example, str == ["abc", 3] =="abcabcabc".
//We define that string s1 can be obtained from string s2 if we can remove some characters from s2 such that it becomes s1.
//For example, s1 = "abc" can be obtained from s2 = "abdbec" based on our definition by removing the bolded underlined characters.
//You are given two strings s1 and s2 and two integers n1 and n2. You have the two strings str1 = [s1, n1] and str2 = [s2, n2].
//Return the maximum integer m such that str = [str2, m] can be obtained from str1.

class Solution {
    public int getMaxRepetitions(String s1, int n1, String s2, int n2) {
        if (s1.length() == 0 || s2.length() == 0) {
            return 0;
        }
        int count = 0;
        int i = 0;
        int j = 0;
        int m = 0;
        while (m < n1) {
            if (s1.charAt(i) == s2.charAt(j)) {
                j++;
                if (j == s2.length()) {
                    j = 0;
                    count++;
                }
            }
            i++;
            if (i == s1.length()) {
                i = 0;
                m++;
            }
        }
        return count / n2;
    }
}