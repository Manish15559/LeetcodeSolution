class Solution {
public:
int dp[10][10][10][20][2][2];
  int helper(int idx,int cnt1,int cnt2,int rem,int tight,int zero,vector<int>&arr,int k ){
    if(idx==arr.size()) return (cnt1==cnt2)&&(rem==0);

    int tot=0;
    if(dp[idx][cnt1][cnt2][rem][tight][zero]!=-1) return dp[idx][cnt1][cnt2][rem][tight][zero];
    for(int num=0;num<=9;num++){
        if(tight&&num>arr[idx]) continue;
        int ntight=tight&&(num==arr[idx]);
        int nrem=((rem*10)+num)%k;
        int nzero=zero&&(num==0);
        if(nzero) tot+=helper(idx+1,cnt1,cnt2,nrem,ntight,nzero,arr,k);
        else tot+=helper(idx+1,(cnt1+(num%2)),(cnt2+(num%2==0)),nrem,ntight,nzero,arr,k);


        

    }
    return dp[idx][cnt1][cnt2][rem][tight][zero]=tot;
  }
  int solve(int n,int k){
    vector<int>arr;
    while(n>0){
        arr.push_back(n%10);
        n/=10;
    }
    reverse(arr.begin(),arr.end());
    memset(dp,-1,sizeof(dp));
    return helper(0,0,0,0,1,1,arr,k);
  }
    int numberOfBeautifulIntegers(int low, int high, int k) {

        int ans=solve(high,k)-solve(low-1,k);

        return ans;
        
    }
};