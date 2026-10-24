class Solution {
public:
    void helper(int idx, int target, vector<int>& curr, vector<int>& candidates,
                vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        if (idx == candidates.size())
            return;
        for (int left = idx; left < candidates.size(); left++) {
            if (idx < left && candidates[left] == candidates[left - 1])
                continue;
            if (target >= candidates[left]) {
                curr.push_back(candidates[left]);
                helper(left + 1, target - candidates[left], curr, candidates,
                       ans);
                curr.pop_back();
            }
            else{
                break;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        vector<vector<int>> ans;
        helper(0, target, curr, candidates, ans);
        return ans;
    }
};