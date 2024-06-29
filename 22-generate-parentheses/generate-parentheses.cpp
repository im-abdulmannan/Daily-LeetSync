class Solution {
public:
    void backtrack(vector<string>& res, int l, int r, string curr, int n) {
        if(curr.length() == 2 * n) {
            res.push_back(curr);
            return;
        }
        if(l < n) {
            backtrack(res, l + 1, r, curr + '(', n);
        }

        if(r < l) {
            backtrack(res, l, r + 1, curr + ')', n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;

        backtrack(res, 0, 0, "", n);
        return res;
    }
};