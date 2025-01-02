class Solution {
public:
const int mod=1e9+7;
long long modpow(int a,int b){
    if(b==0) return 1;
    long long res=modpow(a,b/2);
    if(b%2) return ((res*1ll*res)%mod*a)%mod;
    else return (res*1ll*res)%mod;
}
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if(multiplier==1) return nums;
        int n=nums.size();
        long long  mx=*max_element(nums.begin(),nums.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        for(int i=0;i<n;i++) pq.push({nums[i],i});

        int mod=1e9+7;


        while(multiplier*1ll*pq.top().first<=mx&&k){
            k--;
           
            pq.push({(multiplier*1ll*pq.top().first)%mod,pq.top().second});
            pq.pop();

        }
         long long pow=modpow(multiplier,k/n);
        while(!pq.empty()){
            int val=pq.top().first;
            int ind=pq.top().second;
            pq.pop();
            
            if(k%n){
                --k;
                nums[ind]=((val*1ll*pow)%mod*multiplier)%mod;
            }
            else{
                nums[ind]=((val*1ll*pow))%mod;


            }        }

            return nums;

    }
};