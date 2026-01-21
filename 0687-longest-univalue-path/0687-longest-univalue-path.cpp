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
    int dfs(TreeNode *node,int &maxi){
        if(node==NULL) return 0;

        int lh=dfs(node->left,maxi);
        int rh=dfs(node->right,maxi);
        int len=1;
        if(lh>0&&node->val==node->left->val) len=max(len,(1+lh));
        if(rh>0&&node->val==node->right->val) len=max(len,(1+rh));
        if(lh>0&&rh>0&&node->val==node->left->val&&node->val==node->right->val) maxi=max(maxi,(lh+rh+1));
        maxi=max(maxi,(len));

        return len;
    }
    int longestUnivaluePath(TreeNode* root) {
        int maxi=1;
        dfs(root,maxi);
        return (maxi-1);
    }
};