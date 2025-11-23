class Solution {
public:
int dp[32][2][2];
    int helper(int idx,bool tight,int prev,vector<int>&arr){
        if(idx==arr.size()) return 1;
        int tot=0;
        if(dp[idx][tight][prev]!=-1) return dp[idx][tight][prev];
        for(int bit=0;bit<=1;bit++){
            if(tight&&bit>arr[idx]) continue;
            if(prev==1&&bit==1) continue;
            bool ntight=tight&&(bit==arr[idx]);
            tot+=helper(idx+1,ntight,bit,arr);
            

            
        }
        return dp[idx][tight][prev]=tot;
    }
    int findIntegers(int n) {
        vector<int>arr;
        while(n>0){
            arr.push_back(n%2);
            n/=2;
        }
        cout<<(arr.size())<<endl;
        reverse(arr.begin(),arr.end());
        memset(dp,-1,sizeof(dp));

        return helper(0,true,0,arr);


        
    }
};