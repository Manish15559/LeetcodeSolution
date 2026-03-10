class Solution {
public:
    int helper(int idx,int k,vector<vector<int>>&piles,vector<vector<int>>&dp){
        if(k==0||idx==piles.size()) return 0;
        if(dp[idx][k]!=-1) return dp[idx][k];
        int m=piles[idx].size();
        int ans=0;
        int curr=0;
        for(int take=0;take<=min(m,k);take++){
            if(take>0) curr+=piles[idx][take-1];
            ans=max(ans,(curr+helper(idx+1,(k-take),piles,dp)));


        }
        return dp[idx][k]=ans;
    
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size();
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return helper(0,k,piles,dp);
        
    }
};