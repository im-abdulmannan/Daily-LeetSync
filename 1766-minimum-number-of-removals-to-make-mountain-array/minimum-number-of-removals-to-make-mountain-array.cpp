class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int n = nums.size();
        vector<int> a(n, 1), b(n, 1);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    a[i] = max(a[i], a[j] + 1);
                }
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j > i; --j) {
                if (nums[i] > nums[j]) {
                    b[i] = max(b[i], b[j] + 1);
                }
            }
        }

        int maxMountainLength = 0;

        for (int i = 1; i < n - 1; ++i) {
            if (a[i] > 1 && b[i] > 1) {
                maxMountainLength = max(maxMountainLength, a[i] + b[i] - 1);
            }
        }

        return n - maxMountainLength;
    }
};