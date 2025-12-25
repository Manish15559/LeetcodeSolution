class Solution {
public:
    bool isOverlapping(vector<int>a,vector<int>b){
        return max(a[0],b[0])<=min(a[1],b[1]);
    }
    static bool comp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
        
    }
    int maxTwoEvents(vector<vector<int>>& events) {

        sort(events.begin(),events.end(),comp);
        unordered_map<int,int>pref;
        vector<int>end;
        int curr=0;
        for(auto it:events){
            curr=max(curr,it[2]);
            pref[it[1]]=curr;
            if(end.empty()||end.back()!=it[1]) end.push_back(it[1]);
        }
        int ans=curr;

       for(auto it:events){
        int start=it[0];
        int idx=lower_bound(end.begin(),end.end(),start)-end.begin();
        idx--;
        if(idx>=0) ans=max(ans,(it[2]+pref[end[idx]]));
       }

       return ans;
        
    }
};