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

pair<int,int> traversal(TreeNode *node,int &cnt){  //count sum
    if(node==NULL) return {0,0};

    pair<int,int> left=traversal(node->left,cnt);
    pair<int,int> right=traversal(node->right,cnt);

    int count=left.first+right.first+1;
    int sum=left.second+right.second+(node->val);

    if((sum/count)==(node->val)) cnt++;

    return {count,sum};
}

    int averageOfSubtree(TreeNode* root) {

        int cnt=0;
        

        traversal(root,cnt);

        return cnt;
        
    }
};