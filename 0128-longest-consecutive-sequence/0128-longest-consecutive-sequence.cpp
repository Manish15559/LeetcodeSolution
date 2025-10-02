class Solution {
public:
int helper(int curr,unordered_set<int>&st,unordered_map<int,int>&vis){
    if(vis.find(curr)!=vis.end()) return vis[curr];
    if(st.find(curr)==st.end()) return 0;

    return vis[curr]=1+helper((curr+1),st,vis);
}
    int longestConsecutive(vector<int>& nums) {
    unordered_set<int>st;
    unordered_map<int,int>vis;
    for(auto it:nums) st.insert(it);

    // int cnt=0;
    for(auto it:st){
       helper(it,st,vis);
        
    }
    int ans=0;
    for(auto it:vis) ans=max(ans,it.second);

    return ans;
        
    }
};