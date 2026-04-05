class Solution {
public:
    int countPalindromes(string s) {
        int n = s.size();
        vector<int> cnt(10, 0);
        vector<vector<int>> dp1(n, vector<int>(100, 0));

        for (int i = 0; i < n; i++) {
            if (i > 0)
                dp1[i] = dp1[i - 1];
            for (int num = 0; num < 10; num++) {
                dp1[i][(num * 10 + (s[i] - '0'))] += cnt[num];
            }
            cnt[(s[i] - '0')]++;
        }

        for(int i=0;i<10;i++) cnt[i]=0;
        vector<vector<int>> dp2(n, vector<int>(100, 0));
        for (int i = n - 1; i >= 0; i--) {
            if ((i + 1) < n)
                dp2[i] = dp2[i + 1];
            for (int num = 0; num < 10; num++) {
              
                dp2[i][(num * 10 + (s[i] - '0'))] += cnt[num];
            }
            cnt[(s[i] - '0')]++;
           
        }

        long long ans = 0;
        int mod = 1e9 + 7;

        for (int i = 1; i < n-1; i++) {
            for (int num = 0; num <= 99; num++) {
               
                ans += (dp1[i - 1][num]*1ll*dp2[i + 1][num]);
                ans %= mod;
            }
            cout<<i<<" "<<ans<<endl;
        }
        return ans;
    }
};