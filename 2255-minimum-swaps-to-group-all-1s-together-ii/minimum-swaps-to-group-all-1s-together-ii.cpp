class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int k = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int count = accumulate(nums.begin(), nums.begin() + k, 0);
        int maximum = count;

        for(int i = k; i < n + k; i++) {
            count += nums[i % n] - nums[(i - k + n) % n];
            maximum = max(maximum, count);
        }

        return k - maximum;
    }
};