class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

        if(m*n != original.size()) return {};
        vector<vector<int>> res(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            res[i] = vector<int>(original.begin() + i * n, original.begin() + i * n + n);
        }

        return res;
    }
};