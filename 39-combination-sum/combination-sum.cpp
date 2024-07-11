class Solution {
public:
    void backtrack(vector<vector<int>>& result, vector<int>& curr, vector<int>& candidates, int target, int idx) {
        if(target == 0) {
            result.push_back(curr);
            return;
        }

        for(int i = idx; i < candidates.size(); i++) {
            if(candidates[i] <= target) {
                curr.push_back(candidates[i]);
                backtrack(result, curr, candidates, target - candidates[i], i);
                curr.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;

        backtrack(result, curr, candidates, target, 0);
        return result;
    }
};