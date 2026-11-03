class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        vector<long long> prev1((r - l + 2), 1),
            curr1((r - l + 2), 0); // increasing
        vector<long long> prev2((r - l + 2), 1), curr2((r - l + 2), 0);
        bool f = true;
        int mod = 1e9 + 7;

        for (int i = 1; i < n; i++) {

            long long total2 = 0;
            long long total1 = 0;

            for (int idx = 1; idx <= (r - l + 1); idx++) {
                if (f == true) {
                    curr2[idx] = total2;
                    total2 += prev2[idx];
                    total2 %= mod;
                    int idx2 = (r - l + 1 - idx + 1);
                    curr1[idx2] = total1;
                    total1 += prev1[idx2];
                    total1 %= mod;
                } else {
                    curr1[idx] = total1;
                    total1 += prev1[idx];
                    total1 %= mod;
                    int idx2 = (r - l + 1 - idx + 1);
                    curr2[idx2] = total2;
                    total2 += prev2[idx2];
                    total2 %= mod;
                }
            }
            f = !f;

            prev1 = curr1;
            prev2 = curr2;
        }

        long long ans = 0;
        for (int idx = 1; idx <= (r - l + 1); idx++) {
            ans += (prev1[idx] + prev2[idx]);
            ans %= mod;
        }
        return ans;
    }
};