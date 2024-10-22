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
#define ll long long
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        vector<ll> res;
        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty()) {
            int curr_level = q.size();
            ll sum = 0;

            while(curr_level--) {
                TreeNode* node = q.front(); q.pop();
                sum += (ll)node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.push_back(sum);
        }
        if(k > res.size()) return -1;
        sort(res.begin(), res.end(), greater<ll>());
        return res[k - 1];
    }
};