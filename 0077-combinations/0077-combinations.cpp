class Solution {
public:
    void helper(vector<int>&curr,int n,int k,vector<vector<int>>&ans){
        if(curr.size()==k){
            ans.push_back(curr);
            return;
        }
        int val=0;
        if(curr.size()>0) val=curr.back();
        for(int num=val+1;num<=n;num++){
            curr.push_back(num);
            helper(curr,n,k,ans);
            curr.pop_back();
        }


    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>curr;
        helper(curr,n,k,ans);
        return ans;
        
    }
};