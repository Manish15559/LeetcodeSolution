class Solution {
public:
    void helper(int idx, int target, vector<int>& curr, vector<int>& candidates,
                vector<vector<int>>& ans) {
        if (idx == candidates.size())
            return;
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        helper(idx + 1, target, curr, candidates, ans);
        if (target >= candidates[idx]) {
            curr.push_back(candidates[idx]);
            helper(idx, target - candidates[idx], curr, candidates, ans);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;

        helper(0, target, curr, candidates, ans);
        return ans;
    }
};