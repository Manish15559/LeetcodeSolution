class Solution {
public:
    long long helper(int idx,int prev1,int prev2,int prev3,int n, vector<vector<vector<vector<int>>>>&dp){ //number of way to color from idx to n-1 when prev1,prev2,prev3 color
        if(idx==n) return 1;

        if(dp[idx][prev1][prev2][prev3]!=-1) return dp[idx][prev1][prev2][prev3];

        long long tot=0;
        int mod=1e9+7;
        for(int curr1=1;curr1<=3;curr1++){
            for(int curr2=1;curr2<=3;curr2++){
                for(int curr3=1;curr3<=3;curr3++){
                    if(curr1==curr2||curr2==curr3) continue;
                    if(curr1!=prev1&&curr2!=prev2&&curr3!=prev3) tot+=helper(idx+1,curr1,curr2,curr3,n,dp);
                    tot%=mod;
                }
            }
        }
        return dp[idx][prev1][prev2][prev3]=tot;
    }
    int numOfWays(int n) {

       vector<vector<vector<vector<int>>>>dp(n,vector<vector<vector<int>>>(4,vector<vector<int>>(4,vector<int>(4,-1))));

        return helper(0,0,0,0,n,dp);
        
    }
};