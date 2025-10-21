class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int N=1e5+1;
        vector<int>cnt(N+1,0);
        for(auto it:nums) cnt[it]++;
        vector<int>pref(N+1,0);
        for(int i=1;i<=N;i++) pref[i]=pref[i-1]+cnt[i];
        int ans=0;
        for(int i=1;i<=N;i++){
            int currCount=cnt[i];
            int left=max((int)0,(i-k-1));
            int right=min(N,(i+k));
            int tot=pref[right]-pref[left]-cnt[i];
            ans=max((currCount+min(numOperations,tot)),ans);
        }
        return ans;

        
    }
};