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
        vector<int>ans;

        for(int i=1;i<=n;i++){
            int op1=ways(i,ans);
            if(op1==numWays[i-1]){
                continue;
            }
            ans.push_back(i);
            int op2=ways(i,ans);
            if(op2!=numWays[i-1]) return {};
        }

        return ans;
        
    }
};