/** https://leetcode.com/problems/count-the-repetitions/ */
//We define str = [s, n] as the string str which consists of the string s concatenated n times.
//For example, str == ["abc", 3] =="abcabcabc".
//We define that string s1 can be obtained from string s2 if we can remove some characters from s2 such that it becomes s1.
//For example, s1 = "abc" can be obtained from s2 = "abdbec" based on our definition by removing the bolded underlined characters.
//You are given two strings s1 and s2 and two integers n1 and n2. You have the two strings str1 = [s1, n1] and str2 = [s2, n2].
//Return the maximum integer m such that str = [str2, m] can be obtained from str1.



int getMaxRepetitions(char * s1, int n1, char * s2, int n2){
    int s1_len = strlen(s1);
    int s2_len = strlen(s2);
    int i = 0, j = 0, cnt = 0;
    int cnt_s2 = 0;
    while(cnt < n1){
        if(s1[i] == s2[j]){
            cnt++;
            j++;
            if(j == s2_len){
                cnt_s2++;
                j = 0;
            }
        }
        i++;
        if(i == s1_len){
            i = 0;
            cnt = 0;
        }
    }
    return cnt_s2 * n2 / n1;
    
}
    