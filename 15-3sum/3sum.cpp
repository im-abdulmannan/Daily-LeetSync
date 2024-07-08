class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> result;

        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            
            int l = i + 1;
            int r = n - 1;

            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == 0) {
                    result.push_back({nums[i], nums[l], nums[r]});
                    r -= 1, l += 1;

                    while(l < r && nums[l] == nums[l - 1]) l+=1;
                    while(l < r && nums[r] == nums[r + 1]) r-=1;
                } else if(sum < 0) {
                    l += 1;
                } else if(sum > 0) {
                    r -= 1;
                }
            }
        }
        
        return result;
    }
};