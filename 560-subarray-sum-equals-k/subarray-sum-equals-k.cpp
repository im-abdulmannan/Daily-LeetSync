class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        /* Two Pointers */
        // int n = nums.size();
        // int count = 0;

        // for (int i = 0; i < n; i++) {
        //     int sum = 0;
        //     sum += nums[i];
        //     if (sum == k) {
        //         count += 1;
        //         // continue;
        //     }
        //     for (int j = i + 1; j < n; j++) {
        //         sum += nums[j];
        //         if (sum == k) {
        //             count += 1;
        //         }
        //     }
        // }

        unordered_map<int, int> mp;
        int sum = 0, count = 0;
        mp[sum] = 1;

        // for(int num = 0; num < nums.length(); num++)
        // for(int num = 0; num != nums.end(); num++)
        for(int num : nums) {
            sum = sum + num;
            int diff = sum - k;
            count = count + mp[diff];
            mp[sum]++;
        }

        return count;
    }
};