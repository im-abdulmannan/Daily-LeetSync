class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);

        int left_product = 1;
        for(int i = 0; i < nums.size(); i++) {
            result[i] *= left_product;
            left_product *= nums[i];
        }

        int right_product = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            result[i] *= right_product;
            right_product *= nums[i];
        }

        return result;
    }
};