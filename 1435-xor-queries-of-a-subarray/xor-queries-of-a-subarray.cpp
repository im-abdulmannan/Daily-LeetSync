class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> preXor(n);
        preXor[0] = arr[0];

        for(int i = 1; i < n; i++) {
            preXor[i] = preXor[i - 1] ^ arr[i];
        }

        int m = queries.size();
        vector<int> res(m);
        for(int i = 0; i < m; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            if(l == 0) {
                res[i] = preXor[r];
            } else {
                res[i] = preXor[r] ^ preXor[l - 1];
            }
        }

        return res;
    }
};