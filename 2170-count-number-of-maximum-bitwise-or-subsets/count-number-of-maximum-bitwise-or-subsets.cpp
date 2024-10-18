class Solution {
public:
    void backtrack(const vector<int>& nums, int idx, int currOR, int maxOR, int& cnt) {
        if(currOR == maxOR) cnt++;

        for(int i = idx; i < nums.size(); i++) {
            backtrack(nums, i+1, currOR | nums[i], maxOR, cnt);
        }
    }
    int countMaxOrSubsets(vector<int>& nums) {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int maxOR = 0;
        for(int num : nums) maxOR |= num;

        int cnt = 0;
        backtrack(nums, 0, 0, maxOR, cnt);
        return cnt;
    }
};