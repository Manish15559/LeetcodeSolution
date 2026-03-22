class Solution {
public:
    int find(int left,int right,bool turn,vector<int>&nums,vector<vector<int>>&dp){
        if(left==right) {
            // cout<<turn<<endl;
            if(turn==true) return nums[left];
            else return (-1*nums[left]);
        }
        if(dp[left][right]!=-1) return dp[left][right];
        if(turn){
            return max((find(left+1,right,!turn,nums,dp)+nums[left]),(find(left,right-1,!turn,nums,dp)+nums[right]));
        }
        else{
             return min((find(left+1,right,!turn,nums,dp)-nums[left]),(find(left,right-1,!turn,nums,dp)-nums[right]));

        }
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int value=find(0,n-1,true,nums,dp);
     return value>=0;
        
    }
};