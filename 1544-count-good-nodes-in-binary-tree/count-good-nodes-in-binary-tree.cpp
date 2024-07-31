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
    int countGoodNodes(TreeNode* node, int maxVal) {
        if(!node) return 0;
        int count = 0;

        if(node->val >= maxVal) {
            maxVal = node->val;
            count+=1;
        }

        count += countGoodNodes(node->left, maxVal);
        count += countGoodNodes(node->right, maxVal);

        return count;
    }

    int goodNodes(TreeNode* root) {
        return countGoodNodes(root, INT_MIN);
    }
};