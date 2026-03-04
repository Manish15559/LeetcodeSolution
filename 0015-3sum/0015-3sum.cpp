class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        set<vector<int>> triplets;
        int n = nums.size();
        unordered_set<int> hashSet;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int required = -1 * (nums[i] + nums[j]);
                if (hashSet.find(required)!=hashSet.end()) {
                    vector<int> arr = {nums[i], nums[j], required};
                    sort(arr.begin(), arr.end());
                    triplets.insert(arr);
                }
            }
            hashSet.insert(nums[i]);
        }
        vector<vector<int>> ans;

        for (auto it : triplets) {
            ans.push_back(it);
        }

        return ans;
    }
};