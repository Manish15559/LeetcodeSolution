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
    void postOrder(TreeNode *node,int &curr){
        if(node==NULL) return;
        postOrder(node->right,curr);
         curr+=node->val;
        node->val=curr;
        postOrder(node->left,curr);
       
    }
    TreeNode* bstToGst(TreeNode* root) {
        int curr=0;
        postOrder(root,curr);
        return root;
        
    }
};