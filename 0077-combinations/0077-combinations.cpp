class Solution {
public:
    void helper(vector<int>&curr,int n,int k,vector<vector<int>>&ans){

        if(curr.size()==k){
            ans.push_back(curr);
            return;
        }

        int currValue=0;
        if(curr.size()>0) currValue=curr.back();
        for(int val=currValue+1;val<=n;val++){
            curr.push_back(val);
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