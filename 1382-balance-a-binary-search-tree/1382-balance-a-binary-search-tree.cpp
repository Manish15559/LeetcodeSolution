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
void traversal(TreeNode *curr,vector<TreeNode *>&inorder){
    if(curr==NULL) return;
    traversal(curr->left,inorder);
    inorder.push_back(curr);
    traversal(curr->right,inorder);
}
TreeNode* construct(int low,int high,vector<TreeNode *>&inorder){
    if(low>high) return NULL;
    int mid=(low+high)/2;
    TreeNode *node=inorder[mid];
    node->left = construct(low,mid-1,inorder);
    node->right = construct(mid+1,high,inorder);

    return node;

}
    TreeNode* balanceBST(TreeNode* root) {
         vector<TreeNode *>inorder;
         traversal(root,inorder);
         int n=inorder.size();
         return construct(0,n-1,inorder);
        
    }
};