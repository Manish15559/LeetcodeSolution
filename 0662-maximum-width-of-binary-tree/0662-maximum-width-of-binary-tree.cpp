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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode *,long long>>q; 
        if(root==NULL) return 0;
        long long width=1;
        q.push({root,0});
        while(!q.empty()){
            int sz=q.size();
            long long left=-1;
            long long right=-1;
            long long minimumIdx=-1;
            cout<<endl;
            for(int i=0;i<sz;i++){
                TreeNode * node=q.front().first;
                long long idx=q.front().second;
                q.pop();
                if(left==-1) left=idx;
                right=idx;
                cout<<idx<<" ";
                
                if(node->left) q.push({node->left,(2*(idx-left)+1)});
                if(node->right) q.push({node->right,((2*(idx-left))+2)});
            }
            width=max(width,(right-left+1));
        }
        return width;
    }
};