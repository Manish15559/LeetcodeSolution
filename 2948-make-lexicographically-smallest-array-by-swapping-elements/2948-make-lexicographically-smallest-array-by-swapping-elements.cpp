class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        vector<vector<int>> groups;
        unordered_map<int, int> mp;
        int curr = -1;
        for (int i = 0; i < sorted.size(); i++) {
            if (i == 0 || (sorted[i] - sorted[i - 1]) > limit) {
                groups.push_back({});
                curr++;
            }
            groups[curr].push_back(sorted[i]);
            mp[sorted[i]] = curr;
        }

        vector<int> idx((curr + 1), 0);
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int curr = mp[nums[i]];
            ans.push_back(groups[curr][idx[curr]]);
            idx[curr]++;
        }
        return ans;
    }
};