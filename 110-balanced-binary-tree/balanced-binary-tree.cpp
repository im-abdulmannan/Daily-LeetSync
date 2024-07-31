/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode* node, bool& flag) {
        if(!node || flag == false) return 0;
        int left_height = helper(node->left, flag);
        int right_height = helper(node->right, flag);

        if(abs(left_height - right_height) > 1) flag = false;

        return max(right_height, left_height) + 1; // height of the current level
    }

    bool isBalanced(TreeNode* root) {
        bool flag = true;
        helper(root, flag);
        return flag;
    }
};