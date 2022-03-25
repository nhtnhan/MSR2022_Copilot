/** https://leetcode.com/problems/concatenated-words/ */
//Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.
//A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

bool isConcatenatedHelper(char **words, int wordsSize, char *word, int *visited) {
    if (strlen(word) == 0) {
        return true;
    }
    for (int i = 0; i < wordsSize; i++) {
        if (visited[i] == 1) {
            continue;
        }
        if (strlen(words[i]) > strlen(word)) {
            continue;
        }
        if (strstr(words[i], word) != NULL) {
            visited[i] = 1;
            if (isConcatenatedHelper(words, wordsSize, word + strlen(words[i]), visited)) {
                return true;
            }
            visited[i] = 0;
        }
    }
    return false;
}

bool isConcatenated(char **words, int wordsSize, char *word) {
    int *visited = (int *)malloc(sizeof(int) * wordsSize);
    memset(visited, 0, sizeof(int) * wordsSize);
    return isConcatenatedHelper(words, wordsSize, word, visited);
}


char ** findAllConcatenatedWordsInADict(char ** words, int wordsSize, int* returnSize){
    *returnSize = 0;
    if (wordsSize == 0) {
        return NULL;
    }
    char **res = (char **)malloc(sizeof(char *) * wordsSize);
    for (int i = 0; i < wordsSize; i++) {
        if (isConcatenated(words, wordsSize, words[i])) {
            res[*returnSize] = words[i];
            (*returnSize)++;
        }
    }
    return res;
}


    