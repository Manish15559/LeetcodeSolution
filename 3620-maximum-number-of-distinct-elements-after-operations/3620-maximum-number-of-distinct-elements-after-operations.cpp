class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        map<int,int>mp;
        for(auto it:nums) mp[it]++;

        int ans=0;
        int used=-1e9;
        for(auto it:mp){
            int num=it.first;
            int cnt=it.second;
            int rangeStart=max(used,(it.first-k));
            int rangeEnd=it.first+k;
            if(cnt>(rangeEnd-rangeStart+1)){
                ans+=(rangeEnd-rangeStart+1);
                used=rangeEnd+1;
            }
            else{
                ans+=cnt;
                used=rangeStart+cnt;
            }

        }
        return ans;
        
    }
};