class Solution {
public:
   int ways(int amount,vector<int>&arr){
    int n=arr.size();

    if(n==0) return 0;

    vector<int>dp(amount+1,0);

    for(int target=0;target<=amount;target++) dp[target]=((target%arr[0])==0?1:0);

    for(int idx=1;idx<n;idx++){
        for(int target=0;target<=amount;target++){
            int take=0;
            if(target>=arr[idx]) take=dp[target-arr[idx]];
            int nottake=dp[target];

            dp[target]=take+nottake;
        }
    }

    return dp[amount];
   

   }
    vector<int> findCoins(vector<int>& numWays) {

        int n=numWays.size();
        vector<int>ways(n+1,0);
        vector<int>ans;
        ways[0]=1;
        for(int idx=1;idx<=n;idx++){
            if(ways[idx]==numWays[idx-1]) continue;
            ans.push_back(idx);
            for(int i=idx;i<=n;i++){
                ways[i]+=ways[i-idx];
            }
             if(ways[idx]!=numWays[idx-1]) return {};

        }

        return ans;
        
    }
};