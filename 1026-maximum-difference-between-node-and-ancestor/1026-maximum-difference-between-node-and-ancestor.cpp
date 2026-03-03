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
    int helper(TreeNode *node,int left,int right){
        if(node==NULL) return 0;


        int curr = max(abs(left-node->val),abs(right-node->val));
        int lh =helper(node->left,min(left,node->val),max(right,node->val));
        int rh = helper(node->right,min(left,node->val),max(right,node->val));

        return max({lh,rh,curr});
    }
    int maxAncestorDiff(TreeNode* root) {

     return helper(root,root->val,root->val);
        
    }
};