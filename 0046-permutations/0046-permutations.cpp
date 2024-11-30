class Solution {
public:
void helper(vector<int>&nums,vector<int>&used,vector<int>&curr,vector<vector<int>>&ans){
    if(curr.size()==nums.size()){
        ans.push_back(curr);
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(!used[i]){
            curr.push_back(nums[i]);
            used[i]=1;
            helper(nums,used,curr,ans);
            used[i]=0;
            curr.pop_back();

        }
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int>used(n,0);
        vector<vector<int>>ans;
        vector<int>curr;
        helper(nums,used,curr,ans);
        return ans;
        
    }
};