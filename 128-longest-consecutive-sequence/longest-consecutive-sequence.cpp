class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <= 0) return 0;

        sort(nums.begin(), nums.end());
        int longestSeq = 0;
        int currSeq = 1;

        for(int i = 1; i < nums.size(); i++) {
            while(i < nums.size() && nums[i] == nums[i - 1]) {
                i++;
            }

            if(i < nums.size() && nums[i] == nums[i - 1] + 1) {
                currSeq++;
            } else {
                longestSeq = max(currSeq, longestSeq);
                currSeq = 1;
            }
        }


        return max(longestSeq, currSeq);
    }
};