def main():       
    filename = "concatenated-words"

    context_comment = """
Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.

A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.
"""

    c_content = """


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findAllConcatenatedWordsInADict(char ** words, int wordsSize, int* returnSize){

}
    """

    js_content = """
/**
 * @param {string[]} words
 * @return {string[]}
 */
var findAllConcatenatedWordsInADict = function(words) {
    
};
    """

    java_content = """
class Solution {
    public List<String> findAllConcatenatedWordsInADict(String[] words) {
        
    }
}
    """
    python_content = """
class Solution(object):
    def findAllConcatenatedWordsInADict(self, words):
        \"""
        :type words: List[str]
        :rtype: List[str]
        \"""
        
    """
    extension_content_dict = {".py": python_content, ".java": java_content, ".js": js_content, ".c": c_content}
    extension_path_dict = {".py": "output/python/", ".java": "output/java/", ".js": "output/javascript/", ".c": "output/c/"}
    print("Creating and Copying Comment and Function Name to all dirs...")

    # Read the training data
    for key,value in extension_content_dict.items():
        # write to comment and function name for copilot file
        file = extension_path_dict[key]+filename+key
        with open(file, 'w') as f:
            # write url of the leetcode problem
            if key == ".py":
                f.write("# https://leetcode.com/problems/"+filename+"/\n")
                for comment in context_comment.splitlines():
                    if comment != "":
                        comment_string = '#' + comment + '\n'
                        f.write(comment_string)
            else:
                f.write("/** https://leetcode.com/problems/"+filename+"/"+" */"+"\n")
                for comment in context_comment.splitlines():
                    if comment !="":
                        comment_string = '//' + comment + '\n'
                        f.write(comment_string)
            f.write(value)

main()