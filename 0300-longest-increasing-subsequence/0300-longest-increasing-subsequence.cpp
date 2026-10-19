class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (ans.size() == 0 || ans.back() < nums[i]) {
                ans.push_back(nums[i]);
                continue;
            }
            int idx =
                lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
            if (idx != ans.size())
                ans[idx] = nums[i];
        }
        return ans.size();
    }
};