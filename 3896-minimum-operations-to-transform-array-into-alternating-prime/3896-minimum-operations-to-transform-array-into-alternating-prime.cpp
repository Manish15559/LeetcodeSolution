class Solution {
public:
    int minOperations(vector<int>& nums) {
         int N=1e5+10;
        vector<int>isPrime(N,true);
        isPrime[1]=false;
       
        for(int i=2;i<N;i++){
            if(isPrime[i]==false) continue;
            for(int j=2*i;j<N;j+=i){
                isPrime[j]=false;
            }
        }

        vector<int>prime;
        for(int i=2;i<N;i++){
            if(isPrime[i]) prime.push_back(i);
        }

        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                if(isPrime[nums[i]]){
                    continue;
                }
                else{
                    int idx=upper_bound(prime.begin(),prime.end(),nums[i])-prime.begin();
                    ans+=(prime[idx]-nums[i]);
                }
            }
            else{
                if(isPrime[nums[i]]) {
                    if(nums[i]==2) ans+=2;
                    else ans++;
                }
            }
            // cout<<i<<" "<<ans<<endl;
        }
        return ans;
        
    }
};