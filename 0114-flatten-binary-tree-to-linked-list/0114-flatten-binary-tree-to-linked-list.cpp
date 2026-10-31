/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *prev=NULL;
    void reversePreorder(TreeNode *node,TreeNode* &prev){
        if(node==NULL) return;
        reversePreorder(node->right,prev);
        reversePreorder(node->left,prev);
        node->left=NULL;
        node->right=prev;
        prev=node;
    }
    void flatten(TreeNode* root) {
        if (root == NULL)
            return;
        TreeNode *prev=NULL;
        reversePreorder(root,prev);
    }
};