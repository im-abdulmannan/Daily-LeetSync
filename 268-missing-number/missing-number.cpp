class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (auto num : nums) {
            res += num;
        }

        return ((n * (n + 1)) / 2) - res;
    }
};
