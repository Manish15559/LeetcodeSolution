class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> prev(3, 0); // minimum cost to reach step i
        for (int idx = 1; idx <= n; idx++) {
            int curr = 1e9;
            for (int step = 1; step <= 3; step++) {
                if ((idx - step) < 0)
                    break;
                int val = costs[idx - 1] + prev[step - 1] + (step * step);
                curr = min(curr, val);
            }
            prev[2] = prev[1];
            prev[1] = prev[0];
            prev[0] = curr;
        }
        return prev[0];
    }
};