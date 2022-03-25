/** https://leetcode.com/problems/concatenated-words/ */
//Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.
//A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

class Solution {
    public List<String> findAllConcatenatedWordsInADict(String[] words) {
        List<String> res = new ArrayList<>();
        if (words == null || words.length == 0) return res;
        Arrays.sort(words, (a, b) -> a.length() - b.length());
        for (String word : words) {
            if (word.length() == 0 || !isConcatenated(word, words)) continue;
            res.add(word);
        }
        return res;
    }
    private boolean isConcatenated(String word, String[] words) {
        boolean[] visited = new boolean[word.length() + 1];
        for (int i = 0; i < word.length(); i++) {
            if (dfs(word, i, 0, words, visited)) return true;
        }
        return false;
    }
    private boolean dfs(String word, int index, int count, String[] words, boolean[] visited) {
        if (count == words.length) {
            return index == word.length();
        }
        if (index == word.length()) return false;
        for (int i = index + 1; i <= word.length(); i++) {
            if (visited[i]) continue;
            if (i - index > words[count].length()) continue;
            if (!word.substring(index, i).equals(words[count])) continue;
            visited[i] = true;
            if (dfs(word, i, count + 1, words, visited)) return true;
            visited[i] = false;
        }
        return false;
    }
}
    