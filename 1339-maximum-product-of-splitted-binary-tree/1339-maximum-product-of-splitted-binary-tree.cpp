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
    int findSum(TreeNode *node){
       int leftSum=0;
       if(node->left) leftSum=findSum(node->left);
       int rightSum=0;
       if(node->right) rightSum=findSum(node->right);

       return (leftSum+rightSum+node->val);
    }
    int helper(TreeNode *node,int totSum,long long &ans){
        int leftSum=0;
       if(node->left) leftSum=helper(node->left,totSum,ans);
       ans=max(ans,((totSum-leftSum)*1ll*leftSum));
       int rightSum=0;
       if(node->right) rightSum=helper(node->right,totSum,ans);
       ans=max(ans,((totSum-rightSum)*1ll*rightSum));

       return (leftSum+rightSum+node->val);

    }
    int maxProduct(TreeNode* root) {

        int totSum = findSum(root);

        long long ans=0;

        helper(root,totSum,ans);
        int mod=1e9+7;

        return ans%mod;
        
    }
};