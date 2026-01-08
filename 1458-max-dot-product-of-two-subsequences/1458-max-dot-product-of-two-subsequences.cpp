class Solution {
public:
    //max dot product between subarray nums1 from 0 to idx1 and subarray nums2 from 0 to idx2
    int helper(int idx1,int idx2,vector<int>&nums1,vector<int>&nums2,bool flag,vector<vector<vector<int>>>&dp){
        if(idx1<0||idx2<0) {
            if(flag) return -1e9;
            else return 0;
        }
        if(dp[idx1][idx2][flag]!=-1) return dp[idx1][idx2][flag];

        //skip idx1
        int op1=helper(idx1-1,idx2,nums1,nums2,flag,dp);

        //skip idx2
        int op2=helper(idx1,idx2-1,nums1,nums2,flag,dp);

        //take product

        int op3=(nums1[idx1]*nums2[idx2])+helper(idx1-1,idx2-1,nums1,nums2,false,dp);


        return dp[idx1][idx2][flag]=max({op1,op2,op3});


    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();

        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(2,-1)));

        return helper(n-1,m-1,nums1,nums2,true,dp);
        
    }
};