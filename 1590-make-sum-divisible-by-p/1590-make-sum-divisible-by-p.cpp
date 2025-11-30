class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        long long curr=0;
        for(int i=0;i<n;i++){
            curr+=nums[i];
        }
        if(curr%p==0) return 0;
        unordered_map<int,int>mp;
        int req=curr%p;
        mp[0]=-1;
        curr=0;
        int ans=n;
        for(int i=0;i<n;i++){
            curr+=nums[i];
            curr%=p;
            int val=(curr-req+p)%p;
            if(mp.find(val)!=mp.end()) ans=min(ans,(i-mp[val]));
            mp[curr]=i;

        }
        if(ans==n) return -1;
        else return ans;

        
    }
};