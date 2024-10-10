class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int n = nums.size();
        stack<int> stk;

        for(int i = 0; i < n; i++) {
            if(stk.empty() || nums[stk.top()] > nums[i]) stk.push(i);
        }

        int max_width = 0;

        for(int i = n - 1; i >= 0; i--) {
            while(!stk.empty() && nums[stk.top()] <= nums[i]) {
                max_width = max(max_width, i - stk.top());
                stk.pop();
            }
        }

        return max_width;
    }
};