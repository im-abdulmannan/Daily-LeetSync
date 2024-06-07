class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        int longestSeq = 0;
        int currentSeq = 1;

        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            while (i < nums.size() && nums[i] == nums[i - 1]) {
                i++;
            }
            if (i < nums.size() && nums[i] == nums[i - 1] + 1) {
                currentSeq += 1;
            } else {
                longestSeq = max(longestSeq, currentSeq);
                currentSeq = 1;
            }
        }

        return max(longestSeq, currentSeq);
    }
};