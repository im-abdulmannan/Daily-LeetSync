class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end());

        backtrack_helper(result, candidates, current, target, 0);
        return result;
    }

    void backtrack_helper(vector<vector<int>>& result, vector<int>& candidates, vector<int>& current, int target, int start) {
        if(target == 0) {
            result.push_back(current);
            return;
        }

        for(int i = start; i < candidates.size(); i++) {
            if(candidates[i] <= target) {
                current.push_back(candidates[i]);
                backtrack_helper(result, candidates, current, target - candidates[i], i + 1);
                while(i < candidates.size() - 1 && candidates[i] == candidates[i+1]) i++;
                current.pop_back();
            }
        }
    }
};