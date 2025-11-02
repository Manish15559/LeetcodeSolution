class Solution {
public:

void dfs(int currNode,int previousNode,int &ans,vector<int>adj[],vector<int>reverseAdj[]){
    // cout<<currNode<<endl;
    for(auto adjNode:adj[currNode]){
        // cout<<adjNode<<endl;
        if(adjNode==previousNode) continue;
        //  cout<<previousNode<<" "<<currNode<<" "<<adjNode<<endl;
        ans++;
        dfs(adjNode,currNode,ans,adj,reverseAdj);

    }
    for(auto adjNode:reverseAdj[currNode]){
        if(adjNode==previousNode) continue;
        dfs(adjNode,currNode,ans,adj,reverseAdj);

    }
}

    int minReorder(int n, vector<vector<int>>& connections) {

        vector<int>adj[n];
        vector<int>reverseAdj[n];
        for(auto connection:connections){
            adj[connection[0]].push_back(connection[1]);
            reverseAdj[connection[1]].push_back(connection[0]);
        }
        int oriented=0;

        dfs(0,-1,oriented,adj,reverseAdj);
        return oriented;


        
    }
};