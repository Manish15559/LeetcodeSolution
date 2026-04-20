class Solution {
public:
    long long dp[16][2][8][10];
    long long f(int pos, bool tight, int idx, int prev, vector<int>& lower,
                vector<int>& arr) {

        if (pos == lower.size()) {
            return (idx==7);
        }
        if (dp[pos][tight][idx][prev] != -1)
            return dp[pos][tight][idx][prev];
        long long op = 0;
        for (int num = 0; num <= 9; num++) {
            if (tight && num > lower[pos])
                break;
            if (idx < 7 && arr[idx] == pos && prev > num)
                continue;
            int ntight = tight & (num == lower[pos]);
            int nidx = idx + (idx < 7 && arr[idx] == pos);
            int nprev = (idx < 7 && arr[idx] == pos) ? num : prev;
        // if(idx==6&&nidx==6) cout<<prev<<" "<<num<<endl;

            op += f(pos + 1, ntight, nidx, nprev, lower, arr);
        }

        return dp[pos][tight][idx][prev] = op;
    }
    long long solve(long long l, long long r, vector<int>& arr) {
        vector<int> lower;
       
        l--;
        for (int i = 0; i < 16; i++) {
            lower.push_back(l % 10);
            l /= 10;
        }
        vector<int> upper;
        for (int i = 0; i < 16; i++) {
            upper.push_back(r % 10);
            r /= 10;
        }
        reverse(lower.begin(), lower.end());
        reverse(upper.begin(), upper.end());

        memset(dp, -1, sizeof(dp));

        long long op1 = f(0, true, 0, 0, lower, arr);
        // for(auto it:upper) cout<<it<<" ";
        // cout<<" "<<op1<<endl;
    //    cout<<"m"<<endl;
        memset(dp, -1, sizeof(dp));
        long long op2 = f(0, true, 0, 0, upper, arr);
        // cout<<op2<<endl;

        return (op2 - op1);
    }
    long long countGoodIntegersOnPath(long long l, long long r,
                                      string directions) {

        int row = 0;
        int col = 0;
        vector<int> arr;
        arr.push_back(0);
        for (auto it : directions) {
            if (it == 'R')
                col++;
            else
                row++;
            arr.push_back(((4 * row) + col));
        }
       

        return solve(l, r, arr);
    }
};