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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            vector<int> level_arr;
            int level_size = q.size();

            for(int i = 0; i < level_size; i++) {
                TreeNode* curr_node = q.front();
                q.pop();
                level_arr.push_back(curr_node->val);

                if(curr_node->left) q.push(curr_node->left);
                if(curr_node->right) q.push(curr_node->right);
            }

            result.push_back(level_arr);
        }

        return result;
    }
};