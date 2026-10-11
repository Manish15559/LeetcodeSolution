class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) { return a[0] < b[0]; }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        vector<vector<int>> ans;
        int n = intervals.size();
        ans.push_back(intervals[0]);
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] <= ans.back()[1]) {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};