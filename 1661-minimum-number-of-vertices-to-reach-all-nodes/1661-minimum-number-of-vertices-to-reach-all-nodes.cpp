class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {

        vector<int>indegree(n,0);

        for(auto it:edges){
            indegree[it[1]]++;
        }
        vector<int>ans;
        for(int node=0;node<n;node++) if(indegree[node]==0) ans.push_back(node);

        return ans;
        
    }
};