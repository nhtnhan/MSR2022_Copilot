# https://leetcode.com/problems/concatenated-words/
#Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.
#A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

class Solution(object):
    def findAllConcatenatedWordsInADict(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        def dfs(word, dic):
            if word in dic:
                return True
            for i in range(1, len(word)):
                if word[:i] in dic and dfs(word[i:], dic):
                    return True
            return False
        dic = set(words)
        res = []
        for word in words:
            if dfs(word, dic):
                res.append(word)
        return res