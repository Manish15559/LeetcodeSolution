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
    int depth(TreeNode *node){
        int lh=0;
        int rh=0;
        if(node->left) lh=depth(node->left);
        if(node->right) rh=depth(node->right);

        return (max(lh,rh)+1);
    }
    TreeNode* helper(TreeNode *node,int len){
        len--;
        if(node==NULL||len==0){
            return node;
        }
        TreeNode *left=helper(node->left,len);
        TreeNode *right=helper(node->right,len);
        if(left==NULL) return right;
        else if(right==NULL) return left;
        return node;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int len=depth(root);
        return helper(root,len);
        
    }
};