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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>>traversal;
        if(root==NULL) return traversal;
        queue<TreeNode *>q;
        q.push(root);
        bool leftToRight=true;
        while(!q.empty()){
            int sz=q.size();
            vector<int>curr(sz);
            for(int i=0;i<sz;i++){
            TreeNode * node =q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);

            int idx = leftToRight ? i : (sz-i-1);
            curr[idx]=node->val;




            }

            leftToRight= !leftToRight;

            traversal.push_back(curr);

        }

        return traversal;
        
    }
};