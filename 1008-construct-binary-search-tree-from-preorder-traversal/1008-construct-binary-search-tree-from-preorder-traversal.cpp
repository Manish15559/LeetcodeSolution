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
    TreeNode* construct(int &idx,vector<int>&preorder,int bound){
        if(idx==preorder.size()||preorder[idx]>bound) return NULL;
        TreeNode *root= new TreeNode(preorder[idx]);
        idx++;
        root->left=construct(idx,preorder,root->val);
        root->right=construct(idx,preorder,bound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx=0;
        return construct(idx,preorder,1e9);
        
    }
};