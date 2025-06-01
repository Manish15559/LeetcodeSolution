class Solution {
public:

double check(string curr, string dest,map<string,vector<pair<string,double>>>&adj,set<string>&vis){
   if(adj.find(curr)==adj.end()) return -1.0;
    if(curr==dest) return 1.0;
   vis.insert(curr);
    for(auto it:adj[curr]){
        if(vis.find(it.first)==vis.end()){
        double val=check(it.first,dest,adj,vis);
        if(val!=-1.0) return (val*it.second);
        }
    }
   

    return -1.0;
}
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        int n=equations.size();

        map<string,vector<pair<string,double>>>adj;

        for(int i=0;i<n;i++){
            adj[equations[i][0]].push_back({equations[i][1],values[i]});
            adj[equations[i][1]].push_back({equations[i][0],(double)1/values[i]});
        }

        vector<double>ans;

        for(auto it:queries){
            string start=it[0];
            string end=it[1];
        set<string>vis;

            double  val =check(start,end,adj,vis);
            ans.push_back(val);
        }
        return ans;
        
    }
};