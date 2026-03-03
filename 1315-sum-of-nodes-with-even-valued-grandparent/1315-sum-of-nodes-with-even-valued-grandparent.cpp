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
    int helper(TreeNode *node,bool isParentEven,bool isGrandParentEven){
        if(node==NULL) return 0;
        bool isCurrNodeEven = ((node->val)%2)==0;
        
        int left = helper(node->left,isCurrNodeEven,isParentEven);
        int right = helper(node->right,isCurrNodeEven,isParentEven);

        if(isGrandParentEven) return (left+right+node->val);
        return (left+right);

    }
    int sumEvenGrandparent(TreeNode* root) {

        return helper(root,false,false);
        
    }
};