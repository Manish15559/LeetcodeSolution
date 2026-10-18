class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime,
                          int numLaps) {

        vector<int> minimumTimeWithoutChanging(20, 1e9);
        for (auto it : tires) {
            int f = it[0];
            int r = it[1];
            long long timeTaken = 0;
            for (int lap = 1; lap < 20; lap++) {
                timeTaken += f * pow((long long)r, (lap - 1));
                if (timeTaken > 1e9) {
                    break;
                }
                minimumTimeWithoutChanging[lap] =
                    min(minimumTimeWithoutChanging[lap], (int)timeTaken);
            }
        }
        vector<int> dp(numLaps + 1, 1e9);
        for (int idx = 1; idx <= numLaps; idx++) {
            dp[idx] =
                 (idx <= 19) ? minimumTimeWithoutChanging[idx] : 1e9;
            for (int j = idx - 1; j >= 1; j--) {
                dp[idx] = min(dp[idx], (dp[j] + changeTime + dp[idx - j]));
            }
        }
        return dp[numLaps];
    }
};