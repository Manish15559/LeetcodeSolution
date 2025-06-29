class Solution {
public:
long long binexp(int n,int mod){
    if(n==0) return 1;
    long long val=binexp(n/2,mod);
    if(n%2) return ((val%mod)*2*(val%mod))%mod;
    else return ((val%mod)*(val%mod))%mod;
}
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        int mod=1e9+7;
        int left=0;
        int right=n-1;
        while(left<=right){
            if((nums[left]+nums[right])<=target) {
                ans=(ans%mod+binexp((right-left),mod)%mod)%mod;
                left++;
            }
            else{
                right--;
            }
            
        }
        return ans;
    }
};