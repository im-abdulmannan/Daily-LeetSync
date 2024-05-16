/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool helper(TreeNode* node) {
        if (node->val == 0 || node->val == 1) {
            return node->val == 1;
        } else if (node->val == 2) {
            return helper(node->left) || helper(node->right);
        } else if (node->val == 3) {
            return helper(node->left) && helper(node->right);
        }

        return false;
    }

    bool evaluateTree(TreeNode* root) {
        return helper(root);
    }
};