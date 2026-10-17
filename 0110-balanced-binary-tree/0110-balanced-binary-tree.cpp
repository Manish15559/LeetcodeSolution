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
    int checkBalanced(TreeNode *node){
        if(node==NULL) return 0;

        int lh=checkBalanced(node->left);
        int rh=checkBalanced(node->right);
        if((lh==-1||rh==-1)||abs(rh-lh)>1) return -1;

        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {

        if(root==NULL) return true;

         if(checkBalanced(root)==-1) return false;
         return true;
        
    }
};