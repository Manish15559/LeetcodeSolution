class Solution {
public:
    int helper(bool turn,int left,int right,vector<int>&piles,vector<vector<vector<int>>>&dp){
        if(left>right) return 0;
        if(dp[left][right][turn]!=-1) return dp[left][right][turn];
        if(turn)  return dp[left][right][turn]=max((piles[left]+helper(false,left+1,right,piles,dp)),(piles[right]+helper(false,left,right-1,piles,dp)));
        else return dp[left][right][turn]=min((helper(true,left+1,right,piles,dp)-piles[left]),(helper(true,left,right-1,piles,dp)-piles[right]));
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();

        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,-1)));

        return helper(true,0,n-1,piles,dp);
        
    }
};