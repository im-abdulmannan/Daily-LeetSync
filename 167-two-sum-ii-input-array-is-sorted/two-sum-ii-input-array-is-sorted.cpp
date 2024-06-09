class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if(numbers.size() < 2) return {};
        int l = 0, r = numbers.size() - 1;

        while(l < r) {
            int currSum = numbers[l] + numbers[r];

            if(currSum > target) r--;
            else if(currSum < target) l++;
            else return {l+1, r+1};
        }

        return {};
    }
};
