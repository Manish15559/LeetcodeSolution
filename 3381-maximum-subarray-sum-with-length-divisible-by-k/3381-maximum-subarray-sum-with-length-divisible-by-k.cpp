class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        vector<long long>pref(k,0);
        // pref[0]=0;

        long long ans=-1e15;
        long long curr=0;
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            if(i<(k-1)) pref[i]=curr;
            // if(i==(k-1)) ans = curr;
            if(i>=k-1){
                int idx=i%k;
                ans=max(ans,(curr-pref[idx]));
                pref[idx]=min(pref[idx],curr);
            }
            
        }

        return ans;
        
    }
};