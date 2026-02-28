class Solution {
public:
    int helper(int idx1,int idx2,int direction,string &ring,string &key,int n,int m,vector<vector<vector<int>>>&dp){
        if(idx2==m) return 0;
        if(dp[idx1][idx2][direction]!=-1) return dp[idx1][idx2][direction];
        if(ring[idx1]==key[idx2]){
            return dp[idx1][idx2][direction]=1+helper(idx1,idx2+1,1,ring,key,n,m,dp);
        }
        if(direction==1){
            return  dp[idx1][idx2][direction]=(1+min(helper((idx1+1+n)%n,idx2,2,ring,key,n,m,dp),helper((idx1-1+n)%n,idx2,0,ring,key,n,m,dp)));
        }
        else return  dp[idx1][idx2][direction]=1+helper((idx1+n+((direction==0)?-1:1))%n,idx2,direction,ring,key,n,m,dp);
    }
    int findRotateSteps(string ring, string key) {
        int n=ring.size();
        int m=key.size();

        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(3,-1)));

        return helper(0,0,1,ring,key,n,m,dp);
        
    }
};