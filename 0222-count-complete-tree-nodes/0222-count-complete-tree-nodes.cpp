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
    int leftHeight(TreeNode *node){
        if(node==NULL) return 0;
       
        return 1+leftHeight(node->left);
    }
    int rightHeight(TreeNode *node){
        if(node==NULL) return 0;
        return 1+rightHeight(node->right);
    }
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0 ;
        int left=leftHeight(root->left);
        int right=rightHeight(root->right);
        if(left==right) return pow(2,(left+1))-1;

        return (1+countNodes(root->left)+countNodes(root->right));
        
    }
};