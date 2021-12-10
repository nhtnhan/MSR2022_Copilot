/** https://leetcode.com/problems/house-robber-iii/ */
//The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.
//Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.
//Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int rob(struct TreeNode* root){
    if(!root) return 0;
    int val = root->val;
    if(root->left) val += rob(root->left->left) + rob(root->left->right);
    if(root->right) val += rob(root->right->left) + rob(root->right->right);
    return max(val, rob(root->left) + rob(root->right));
}

int rob(struct TreeNode* root) {
    return rob_helper(root, 0);
}

int rob_helper(struct TreeNode* root, int prev) {
    if (!root) {
        return 0;
    }
    int val = root->val;
    if (prev) {
        val *= 2;
    }
    return max(val + rob_helper(root->left, 0) + rob_helper(root->right, 1), rob_helper(root->left, 1) + rob_helper(root->right, 0));
}
    