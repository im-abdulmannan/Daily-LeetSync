class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int count_ones = count(nums.begin(), nums.end(), 1);
        if(count_ones == 0) return 0;

        vector<int> extended_array(nums.begin(), nums.end());
        extended_array.insert(extended_array.end(), nums.begin(), nums.end());

        int current_zero = count(extended_array.begin(), extended_array.begin() + count_ones, 0);
        int min_zero = current_zero;

        for(int i = count_ones; i < extended_array.size(); i++) {
            if(extended_array[i] == 0) current_zero++;
            if(extended_array[i - count_ones] == 0) current_zero--;

            min_zero = min(min_zero, current_zero);
        }

        return min_zero;
    }
};