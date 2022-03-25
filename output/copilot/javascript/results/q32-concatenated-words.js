/** https://leetcode.com/problems/concatenated-words/ */
//Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.
//A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

/**
 * @param {string[]} words
 * @return {string[]}
 */
 var findAllConcatenatedWordsInADict = function(words) {
    let res = [];
for(let i=0; i<words.length; i++){
   if(isConcatenated(words[i])){
       res.push(words[i]);
   }
}
return res;
}
