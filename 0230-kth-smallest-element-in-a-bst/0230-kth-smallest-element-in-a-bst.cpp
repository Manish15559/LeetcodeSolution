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
    int inorder(TreeNode *node,int &count,int k){
        if(node==NULL) return -1;
        int left=inorder(node->left,count,k);
        if(left!=-1) return left;
        count++;
        if(count==k) return node->val;
        int right=inorder(node->right,count,k);
        if(right!=-1) return right;
        return -1;
        
    }
    int kthSmallest(TreeNode* root, int k) {
        //inorder
        int count=0;
        return inorder(root,count,k);
        
    }
};