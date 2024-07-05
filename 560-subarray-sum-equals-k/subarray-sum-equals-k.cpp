class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> mp;
        int sum = 0, count = 0;
        mp[sum] = 1;

        for(int num : nums) {
            sum = sum + num;
            int diff = sum - k;
            if(mp.count(diff))
                count = count + mp[diff];
            mp[sum]++;
        }

        return count;
    }
};