class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        helper(candidates, result, curr, target, 0);
        return result;
    }

    void helper(vector<int>& candidates, vector<vector<int>>& result, vector<int>& curr, int target, int start) {
        if(target == 0) {
            result.push_back(curr);
            return;
        }
       
        for(int i = start; i < candidates.size(); i++) {
            if(candidates[i] <= target) {
                curr.push_back(candidates[i]);
                helper(candidates, result, curr, target - candidates[i], i + 1);
                while(i < candidates.size() - 1 && candidates[i] == candidates[i + 1]) i++;
                curr.pop_back();
            }
        }
    }
};