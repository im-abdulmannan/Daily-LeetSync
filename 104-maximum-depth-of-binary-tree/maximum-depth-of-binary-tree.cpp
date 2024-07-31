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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;

        queue<TreeNode*> nodes;
        nodes.push(root);
        int depth = 0;

        while(!nodes.empty()) {
            int size = nodes.size();
            for(int i = 0; i < size; i++) {
                TreeNode* curr = nodes.front();
                nodes.pop();

                if(curr->left) nodes.push(curr->left);
                if(curr->right) nodes.push(curr->right);
            }
            depth++;
        }

        return depth;
    }
};