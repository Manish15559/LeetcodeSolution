class Solution {
public:
    void dfs(int node,int currMask,vector<int>&mask,vector<pair<int,int>>adj[]){
        mask[node]=currMask;
        for(auto it:adj[node]){
            dfs(it.first,(currMask^(1<<it.second)),mask,adj);
        }
        return;

    }
    long long countPalindromePaths(vector<int>& parent, string s) {
        int n=parent.size();
        vector<pair<int,int>>adj[n];

        for(int i=1;i<n;i++){
            adj[parent[i]].push_back({i,(s[i]-'a')});

        }
        vector<int>mask(n,0);
        dfs(0,0,mask,adj);
        unordered_map<int,int>cnt;

        for(auto it:mask) cnt[it]++;
        long long ans=0;
        for(auto it:mask){
            ans+=(cnt[it]-1);
            for(int i=0;i<26;i++){
                int value=it^(1<<i);
                ans+=cnt[value];
            }
        }
        return ans/2;
        
    }
};