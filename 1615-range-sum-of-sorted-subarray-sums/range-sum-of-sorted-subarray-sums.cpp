class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // sort(nums.begin(), nums.end());
        vector<int> result;
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum += nums[j];
                result.push_back(sum);
            }
        }
        sort(result.begin(), result.end());
        // for(int re : result) cout << re << " ";
        int ans = 0;
        const int MOD = 1e9 + 7;
        for(int i = left - 1; i < right; i++) {
            ans = (ans + result[i]) % MOD;
        }

        return ans;
    }
};