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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(!root) return nullptr;

        queue<TreeNode*> q;
        q.push(root);
        int prev = root->val;

        while(!q.empty()) {
            int curr_level = q.size();
            int curr = 0;

            while(curr_level > 0) {
                TreeNode* temp = q.front();
                q.pop();

                int leftRight = (temp->left ? temp->left->val : 0) + (temp->right ? temp->right->val : 0);

                if(temp->left) {
                    temp->left->val = leftRight;
                    q.push(temp->left);
                }

                if(temp->right) {
                    temp->right->val = leftRight;
                    q.push(temp->right);
                }

                curr += leftRight;
                temp->val = prev - temp->val;
                curr_level--;
            }
            prev = curr;
        }

        return root;
    }
};