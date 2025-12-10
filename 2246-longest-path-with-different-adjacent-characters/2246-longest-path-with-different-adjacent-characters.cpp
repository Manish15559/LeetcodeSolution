class Solution {
public:
    int traversal(int node,vector<int>adj[],string &s,int &ans){
        if(adj[node].size()==0) return 1;
        int mx1=0;
        int mx2=0;
        for(auto it:adj[node]){
            int val=traversal(it,adj,s,ans);
            if(s[it]==s[node]) val=1;
            else val++;
            if(mx1<val){
                mx2=mx1;
                mx1=val;

            }
            else if(mx2<val){
                mx2=val;
            }
        }
        if(mx2==0) ans=max(ans,mx1);
        else ans=max(ans,(mx2+mx1-1));

        return mx1;
    }
    int longestPath(vector<int>& parent, string s) {
        int n=parent.size();
        vector<int>adj[n];

        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
        int ans=1;

        traversal(0,adj,s,ans);

        return ans;



        
    }
};