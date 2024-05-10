class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> current;

        helper(result, current, k, n, 1);
        return result;
    }

    void helper(vector<vector<int>>& result, vector<int>& current, int k, int target, int start) {
        if(k < 0) return;
        if (target == 0 && k == 0) {
            result.push_back(current);
            return;
        }

        for(int i = start; i <= min(target, 9); i++) {
            if(i <= target) {
                current.push_back(i);
                helper(result, current, k - 1, target - i, i+1);
                current.pop_back();
            }
        }
    }
};