class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int maxi = *max_element(nums.begin(), nums.end());
        int len = 1;
        int tempLen = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == maxi) {
                tempLen++;
            } else {
                len = max(len, tempLen);
                tempLen = 0;
            }
        }

        len = max(len, tempLen);

        return len;
    }
};