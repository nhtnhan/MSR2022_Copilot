/** https://leetcode.com/problems/unique-substrings-in-wraparound-string/ */
//We define the string s to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", so s will look like this:
//"...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
//Given a string p, return the number of unique non-empty substrings of p are present in s.

class Solution {
    public int findSubstringInWraproundString(String p) {
        int[] count = new int[26];
        int max = 0;
        for (int i = 0; i < p.length(); i++) {
            char c = p.charAt(i);
            if (i > 0 && (p.charAt(i - 1) - c + 26) % 26 == 1) {
                max++;
            } else {
                max = 1;
            }
            count[c - 'a'] = Math.max(count[c - 'a'], max);
        }
        int res = 0;
        for (int i = 0; i < 26; i++) {
            res += count[i];
        }
        return res;
    }
}