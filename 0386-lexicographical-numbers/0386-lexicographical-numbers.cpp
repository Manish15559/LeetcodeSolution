class Solution {
public:
void dfs(int curr,int mx,vector<int>&ans){

    

    for(int i=0;i<=9;i++){
        int next=(10*curr)+i;
       
        if(next==0) continue;

        if(next>mx) break;
         
         ans.push_back(next);
        dfs(next,mx,ans);
    }
}
    vector<int> lexicalOrder(int n) {

        vector<int>ans;

       
        dfs(0,n,ans);

        return ans;
        
    }
};