class Solution {
public:
    static bool compEnd(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }

    static bool compStart(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();

      
        vector<vector<int>> endTime = events;
        vector<vector<int>> startTime = events;

        sort(endTime.begin(), endTime.end(), compEnd);
        sort(startTime.begin(), startTime.end(), compStart);

        int idx = 0;
        int bestEndedValue = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {
           
            ans = max(ans, startTime[right][2]);

            
            while (idx < n && endTime[idx][1] < startTime[right][0]) {
                bestEndedValue = max(bestEndedValue, endTime[idx][2]);
                idx++;
            }

           
            ans = max(ans, bestEndedValue + startTime[right][2]);
        }

        return ans;
    }
};
