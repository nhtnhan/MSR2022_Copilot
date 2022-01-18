/** https://leetcode.com/problems/count-the-repetitions/ */
//We define str = [s, n] as the string str which consists of the string s concatenated n times.
//For example, str == ["abc", 3] =="abcabcabc".
//We define that string s1 can be obtained from string s2 if we can remove some characters from s2 such that it becomes s1.
//For example, s1 = "abc" can be obtained from s2 = "abdbec" based on our definition by removing the bolded underlined characters.
//You are given two strings s1 and s2 and two integers n1 and n2. You have the two strings str1 = [s1, n1] and str2 = [s2, n2].
//Return the maximum integer m such that str = [str2, m] can be obtained from str1.

/**
 * @param {string} s1
 * @param {number} n1
 * @param {string} s2
 * @param {number} n2
 * @return {number}
 */
 var getMaxRepetitions = function(s1, n1, s2, n2) {
    let s1_len = s1.length;
    let s2_len = s2.length;
    let s1_idx = 0;
    let s2_idx = 0;
    let count = 0;
    for(let i = 0; i < n1; i++) {
        let s1_c = s1[s1_idx];
        let s2_c = s2[s2_idx];
        if(s1_c === s2_c) {
            s2_idx++;
            if(s2_idx === s2_len) {
                count++;
                s2_idx = 0;
            }
        }
        s1_idx++;
        if(s1_idx === s1_len) {
            s1_idx = 0;
        }
    }
    return count / n2;
}
   