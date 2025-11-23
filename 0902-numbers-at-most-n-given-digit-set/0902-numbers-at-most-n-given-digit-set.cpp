class Solution {
public:
int dp[10][2][2];
   int helper(int idx,bool tight,bool zero,vector<string>&digits,vector<int>&arr){
    if(idx==arr.size()) return zero==false;
    int tot=0;
    if(dp[idx][tight][zero]!=-1) return dp[idx][tight][zero];
    for(auto it:digits){
        int num=it[0]-'0';
        if(tight&&num>arr[idx]) continue;
        bool ntight =(tight&&(num==arr[idx]));
        bool nzero=(zero&&(num==0));
        tot+=helper(idx+1,ntight,nzero,digits,arr);
    }
    if(zero) tot+=helper(idx+1,false,zero,digits,arr);
    return dp[idx][tight][zero]=tot;
   }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        vector<int>arr;
        while(n>0){
            arr.push_back(n%10);
            n/=10;
        }
        reverse(arr.begin(),arr.end());
        memset(dp,-1,sizeof(dp));
        return helper(0,true,true,digits,arr);
        
    }
};