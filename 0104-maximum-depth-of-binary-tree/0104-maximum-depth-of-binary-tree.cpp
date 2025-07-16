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
int helper(TreeNode *node){
    if(node==NULL) return 0;
    int left=helper(node->left);
    int right=helper(node->right);
    return 1+max(left,right);
}
    int maxDepth(TreeNode* root) {
    return helper(root);
        
    }
};