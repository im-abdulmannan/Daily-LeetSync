class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;

        for (int i = 0; i < nums.size(); i++) {
            int comp = target - nums[i];

            if (hash.find(comp) != hash.end())
                return {hash[comp], i};
            hash[nums[i]] = i;
        }

        return {};
    }
};