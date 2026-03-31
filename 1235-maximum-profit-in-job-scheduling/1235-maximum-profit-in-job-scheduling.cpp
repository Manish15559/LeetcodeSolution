class Solution {
public:
    int find(int val, vector<pair<int, int>>& arr) {
        if (arr.size() == 0)
            return 0;
        if (arr[0].first > val)
            return 0;
        int low = 0;
        int high = arr.size() - 1;
        while ((high - low) > 1) {
            int mid = (low + high) / 2;
            if (arr[mid].first <= val)
                low = mid;
            else
                high = mid - 1;
        }
        if (arr[high].first <= val)
            return arr[high].second;
        return arr[low].second;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {

        vector<vector<int>> arr;
        int n = startTime.size();
        for (int i = 0; i < n; i++) {
            arr.push_back({endTime[i], startTime[i], profit[i]});
        }
        sort(arr.begin(), arr.end());

        vector<pair<int, int>> dp;

        for (int i = 0; i < n; i++) {
            // take
            int take = find(arr[i][1], dp) + arr[i][2];

            int nottake = 0;
            if (dp.size() > 0)
                nottake = dp.back().second;

            dp.push_back({arr[i][0], max(take, nottake)});
        }

        return dp.back().second;
    }
};