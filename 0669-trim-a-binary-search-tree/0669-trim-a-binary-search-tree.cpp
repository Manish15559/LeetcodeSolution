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
    TreeNode *helper(TreeNode *node,int low,int high){
        if(node==NULL) return NULL;
        int value=node->val;
        if(low<=value&&value<=high){
            node->left = helper(node->left,low, high);
            node->right = helper(node->right,low,high);
            return node;
        }
        else if(low>value){
            return helper(node->right,low,high);
        }
        else{
            return helper(node->left,low,high);
        }
        // return NULL;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return helper(root,low,high);
        
    }
};