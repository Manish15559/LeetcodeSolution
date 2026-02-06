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
    TreeNode* traversal(TreeNode *node){
        if(node==NULL) return NULL;
        node->left = traversal(node->left);
        node->right =traversal(node->right);

        if(node->left==NULL&&node->right==NULL&&node->val==0) return NULL;
        else return node;
    }
    TreeNode* pruneTree(TreeNode* root) {

        return traversal(root);
        
    }
};