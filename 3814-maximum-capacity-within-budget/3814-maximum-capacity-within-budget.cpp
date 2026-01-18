class Solution {
public:
    int find(int val,int limit,vector<pair<int,int>>&arr,vector<int>&pref){
        int low=0;
        int high=limit;
        if(limit<0||arr[0].first>val) return 0;
        while(high-low>1){
            int mid=(low+high)/2;
            if(arr[mid].first>val) high=mid-1;
            else low=mid;
        }
        if(arr[high].first<=val) return pref[high];
        else return pref[low];

    }
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        vector<pair<int,int>>arr;
        int n=costs.size();
        for(int i=0;i<n;i++) arr.push_back({costs[i],capacity[i]});
        sort(arr.begin(),arr.end());
        vector<int>pref;
        for(int i=0;i<n;i++){
            if(i==0) pref.push_back(arr[i].second);
            else pref.push_back(max(pref.back(),arr[i].second));
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(arr[i].first>=budget) break;
            ans=max(ans,arr[i].second);
            int left=budget-arr[i].first-1;
            int val=find(left,i-1,arr,pref);
            ans=max(ans,(val+arr[i].second));
        }
        return ans;
        
    }
};