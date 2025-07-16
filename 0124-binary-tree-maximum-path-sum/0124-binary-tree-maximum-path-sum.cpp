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
  int helper(TreeNode *node,int &ans){
    if(node==NULL) return 0;
    int lh=helper(node->left,ans);
    int rh=helper(node->right,ans);
    ans=max(ans,(lh+rh+node->val));
    int curr = node->val+max(lh,rh);
    if(curr<=0) return 0;
    else return curr;
  }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        helper(root,ans);
        return ans;
        
    }
};