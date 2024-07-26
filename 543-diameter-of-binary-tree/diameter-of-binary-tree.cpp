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
    int helper(TreeNode* curr, int& res) {
        if(!curr) return 0;

        int left = helper(curr->left, res);
        int right = helper(curr->right, res);

        res = max(res, left + right);

        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
};