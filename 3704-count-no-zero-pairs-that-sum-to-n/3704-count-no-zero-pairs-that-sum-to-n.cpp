class Solution {
public:
long long dp[16][2][2][2];
    long long helper(int idx,int carry,int zero1,int zero2,vector<int>&arr){
        if(idx==arr.size()) return carry==0;
        
        if(dp[idx][carry][zero1][zero2]!=-1) return dp[idx][carry][zero1][zero2];
        int val=arr[idx]-carry;
        val=(val+10)%10;
       
        long long tot=0;
        for(int i=0;i<=9;i++){
            for(int j=0;j<=9;j++){
                int curr=(i+j);
                // if(val==0)
                if((curr%10)!=val) continue;
                if(idx==0&&(j==0)) continue;
                if(idx==0&&i==0) continue;
                if(zero1&&i>0) continue;
                if(zero2&&j>0) continue;
                int nzero1=zero1||(i==0);
                int nzero2=zero2||(j==0);
                tot+=helper(idx+1,((curr+carry)>=10),nzero1,nzero2,arr);
            }
        }
        return dp[idx][carry][zero1][zero2]=tot;
        
    }
    long long countNoZeroPairs(long long n) {
        vector<int>arr;
        while(n>0){
            arr.push_back(n%10);
            n/=10;
        }
        memset(dp,-1,sizeof(dp));
        return helper(0,0,0,0,arr);

        
    }
};