class Solution {
public:
    bool isColoringPossible(int node,int currColor,vector<vector<int>>&graph,vector<int>&color){
        color[node]=currColor;
        for(auto adjNode:graph[node]){
            if(color[adjNode]==-1){
                if(isColoringPossible(adjNode,!currColor,graph,color)==false) return false;
            }
            else if(color[adjNode]==color[node]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {

        int n=graph.size();
        vector<int>color(n,-1);
        for(int node=0;node<n;node++){
            if(color[node]==-1){
                if(isColoringPossible(node,0,graph,color)==false) return false;
            }
        }
        return true;
        
    }
};