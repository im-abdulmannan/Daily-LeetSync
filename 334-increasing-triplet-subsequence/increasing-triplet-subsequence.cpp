class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3) return false;
        int a = nums[0], b = INT_MAX;
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] <= a) {
                a = nums[i];
            } else if (nums[i] <= b) {
                b = nums[i];
            } else {
                return true;
            }
        }

        return false;
    }
};