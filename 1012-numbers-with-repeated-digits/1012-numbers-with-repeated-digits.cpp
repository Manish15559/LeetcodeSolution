class Solution {
public:
int dp[10][(1<<10)][2][2];
   int helper(int idx,int mask,bool tight,bool zero,vector<int>&arr){

    if(idx==arr.size()) {
        cout<<mask<<endl;
        return (zero==false);
    }
    
    if(dp[idx][mask][tight][zero]!=-1) return dp[idx][mask][tight][zero];
    int sum=0;
    for(int num=0;num<=9;num++){
        // cout<<num<<" "<<idx<<endl;
        if((mask>>num)&1) continue;
        if(tight==true&&num>arr[idx]) {
            // cout<<idx<<" "<<num<<endl;
            continue;
        }
        int ntight=(tight&&(num==arr[idx]));
        int nzero=(zero&&(num==0));
        int nmask=nzero ? mask: (mask|(1<<num));
        // cout<<nzero<<endl;
        sum+=helper(idx+1,nmask,ntight,nzero,arr);


    }
    return dp[idx][mask][tight][zero]=sum;
   }
    int numDupDigitsAtMostN(int n) {
        int k=n;
        vector<int>arr;
        while(n>0){
            arr.push_back(n%10);
            n/=10;
        }
        reverse(arr.begin(),arr.end());
        memset(dp,-1,sizeof(dp));
        return (k-helper(0,0,true,true,arr));
        
    }
};