class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int sumOfSubArr[n * (n + 1) / 2];
        for(int i = 0, k = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum += nums[j];
                sumOfSubArr[k++] = sum;
            }
        }

        sort(sumOfSubArr, sumOfSubArr + (n * (n + 1) / 2));
        int ans = 0;
        const int MOD = 1e9 + 7;
        for(int i = left - 1; i < right; i++) {
            ans = (ans + sumOfSubArr[i]) % MOD;
        }

        return ans;
    }
};