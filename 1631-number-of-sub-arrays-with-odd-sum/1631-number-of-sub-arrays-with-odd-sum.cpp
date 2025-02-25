class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {

        int n=arr.size();
      

       int cnt[2]={0};
       cnt[0]++;
       int sum=0;
       int ans=0;
       int mod=1e9+7;
      
        for(int i=0;i<n;i++){
            sum+=arr[i];
            sum%=2;
            ans+=cnt[(sum)?0:1];
            ans%=mod;
            cnt[sum]++;

        }
        
        return ans;
        
    }
};