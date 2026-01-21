/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode *node,long long &curr,int targetSum,int &cnt,unordered_map<long long,int>&val){
        if(node==NULL) return;

        curr+=node->val;

        if(val.find((curr-targetSum))!=val.end()) cnt+=val[(curr-targetSum)];

        val[curr]++;
        dfs(node->left,curr,targetSum,cnt,val);
        dfs(node->right,curr,targetSum,cnt,val);
        val[(curr)]--;
        curr-=(node->val);
        


    }
    int pathSum(TreeNode* root, int targetSum) {
        long long curr=0;
        int ans=0;
        unordered_map<long long,int>val;
        val[0]++;
        dfs(root,curr,targetSum,ans,val);

        return ans;
        
    }
};