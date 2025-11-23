class Solution {
public:
long long dp1[17][10][10][2][2];
long long dp2[17][10][10][2][2];

    pair<long long,long long> helper(int idx, int prev, int prev2, bool start, bool flag,
                     vector<int>& arr) {
        if (idx == arr.size())
            return {0,1};
        long long ans = 0;
        long long tot=0;
        if(dp1[idx][prev][prev2][start][flag]!=-1) return {dp1[idx][prev][prev2][start][flag],dp2[idx][prev][prev2][start][flag]};
        for (int num = 0; num <= 9; num++) {
            bool f = flag;
            if (f == true && num > arr[idx])
                continue;
            f = f & (num == arr[idx]);
            bool s = (start || (prev2 != 0));
            int check = 0;
            if (s)
                check = ((prev2 < prev) && (prev > num)) ||
                        ((prev2 > prev) && (prev < num));
         
            auto val = helper(idx + 1, num, prev, s, f, arr);
        long long cnt=0;
            if(check) cnt=val.second;
            ans += (val.first+cnt);
            tot+=val.second;
        }
        return {dp1[idx][prev][prev2][start][flag]=ans,dp2[idx][prev][prev2][start][flag]=tot};
    }
    pair<long long,long long> solve(long long num) {
        vector<int> arr;
        string str = to_string(num);
        int n = str.size();
        while (num > 0) {
            arr.push_back((num % 10));
            num /= 10;
        }
        reverse(arr.begin(), arr.end());
        memset(dp1,-1,sizeof(dp1));
         memset(dp2,-1,sizeof(dp2));
    
        return helper(0, 0, 0, false, true, arr);
    }
    long long totalWaviness(long long num1, long long num2) {
        long long x = solve(num2).first;
        long long y = solve((num1 - 1)).first;
        cout << y << endl;
        cout << x << endl;
        long long ans = x - y;
        return ans;
    }
};