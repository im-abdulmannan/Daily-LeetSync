class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n, 0);

        if(k == 0) return res;

        for(int i = 0; i < n; i++) {
            int sum = 0, cnt = k;
            int j = 0;

            if(k > 0) {
                j = i + 1;
                while(cnt--) {
                    sum += code[j % n];
                    j++;
                }
            } else if(k < 0) {
                if(i == 0) j = n - 1;
                else j = i - 1;
                while(cnt++) {
                    sum += code[j];
                    if(j == 0) j = n - 1;
                    else j--;
                }
            }

            res[i] = sum;
        }

        return res;
    }
};