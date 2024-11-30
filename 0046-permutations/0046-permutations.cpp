class Solution {
public:
void helper(int idx, vector<int>& nums, vector<vector<int>>& ans) {
    if (idx == nums.size()) {
        ans.push_back(nums);
        return;
    }
    for (int i = idx; i < nums.size(); i++) {
        swap(nums[idx], nums[i]); // Swap to fix one element
        helper(idx + 1, nums, ans); // Recursive call
        swap(nums[idx], nums[i]); // Backtrack to restore original state
    }
}

// Function to generate all permutations in lexicographical order
vector<vector<int>> permute(vector<int>& nums) {
    sort(nums.begin(), nums.end()); // Ensure lexicographical order
    vector<vector<int>> ans;
    helper(0, nums, ans);
    return ans;
}
};