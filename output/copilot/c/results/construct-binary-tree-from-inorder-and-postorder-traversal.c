/** https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/ */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    if(inorderSize == 0) return NULL;
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = postorder[postorderSize - 1];
    root->left = NULL;
    root->right = NULL;
    int i;
    for(i = 0; i < inorderSize; i++){
        if(inorder[i] == root->val){
            root->left = buildTree(inorder, i, postorder, i);
            root->right = buildTree(inorder + i + 1, inorderSize - i - 1, postorder + i, postorderSize - i - 1);
        }
    }
    return root;
}
    