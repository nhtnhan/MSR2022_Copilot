/** https://leetcode.com/problems/unique-substrings-in-wraparound-string/ */
//We define the string s to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", so s will look like this:
//"...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
//Given a string p, return the number of unique non-empty substrings of p are present in s.

/**
 * @param {string} p
 * @return {number}
 */
 var findSubstringInWraproundString = function(p) {
    let map = new Map();
let count = 0;
for (let i = 0; i < 26; i++) {
 map.set(String.fromCharCode(97 + i), 1);
}
for (let i = 0; i < p.length; i++) {
 if (p[i] !== p[i + 1]) {
   count += map.get(p[i]);
   map.set(p[i], 1);
 } else {
   let count = map.get(p[i]) + 1;
   map.set(p[i], count);
 }
}
return count;
};
 