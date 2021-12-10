/** https://leetcode.com/problems/unique-substrings-in-wraparound-string/ */
//We define the string s to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", so s will look like this:
//"...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
//Given a string p, return the number of unique non-empty substrings of p are present in s.



int findSubstringInWraproundString(char * p){
    int n = strlen(p);
    int *count = (int *)calloc(26, sizeof(int));
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0 && (p[i] - p[i - 1] == 1 || p[i] - p[i - 1] == -25)) {
            max++;
        } else {
            max = 1;
        }
        count[p[i] - 'a'] = max;
    }
    int res = 0;
    for (int i = 0; i < 26; i++) {
        res += count[i];
    }
    return res;
}
    