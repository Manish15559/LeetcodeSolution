class Solution {
public:
enum Orientation{ Original, Reverse};
void dfs(int currNode,int previousNode,int &ans, vector<pair<int,int>>adj[]){
    // cout<<currNode<<endl;
    for(auto adjNode:adj[currNode]){
        // cout<<adjNode<<endl;
        if(adjNode.first==previousNode) continue;
        //  cout<<previousNode<<" "<<currNode<<" "<<adjNode<<endl;
        if(adjNode.second==1) ans++;
        dfs(adjNode.first,currNode,ans,adj);

    }
    
}

    int minReorder(int n, vector<vector<int>>& connections) {

        vector<pair<int,int>>adj[n];
        // vector<int>reverseAdj[n];
        for(auto connection:connections){
            adj[connection[0]].push_back({connection[1],1});
            adj[connection[1]].push_back({connection[0],0});
        }
        int oriented=0;

        dfs(0,-1,oriented,adj);
        return oriented;


        
    }
};