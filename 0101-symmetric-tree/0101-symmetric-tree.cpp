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
    bool checkSymmetric(TreeNode *leftNode,TreeNode *rightNode){
        if(leftNode==NULL&&rightNode==NULL) return true;
        else if(leftNode==NULL) return false;
        else if(rightNode==NULL) return false;
        else if(leftNode->val==rightNode->val) return checkSymmetric(leftNode->left,rightNode->right)&checkSymmetric(leftNode->right,rightNode->left);

        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return false;

        return checkSymmetric(root->left,root->right);
        
    }
};