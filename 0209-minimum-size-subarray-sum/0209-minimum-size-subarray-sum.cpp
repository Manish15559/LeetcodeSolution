class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
    vector<int>pref;
    int sum=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        sum+=nums[i];
        pref.push_back(sum);

    }
    int ans=1e9;
    sum=0;
    for(int i=0;i<n;i++){
        int idx=lower_bound(pref.begin(),pref.end(),(sum+target))-pref.begin();
        if(idx>=n) break;
        ans=min(ans,(idx-i+1));
        sum+=nums[i];
    }
    if(ans==1e9) return 0;
    return ans;

       
        
    }
};