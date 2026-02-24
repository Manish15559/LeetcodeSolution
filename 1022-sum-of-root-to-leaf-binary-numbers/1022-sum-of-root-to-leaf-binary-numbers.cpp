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
    bool isLeaf(TreeNode* node) {
        return ((node->left == NULL) && (node->right == NULL));
    }
    int dfs(TreeNode* node, int curr) {
        if (node == NULL)
            return 0;
        curr = 2 * curr + node->val;
        if (isLeaf(node)) {
            return curr;
        }

        return dfs(node->left, curr) + dfs(node->right, curr);
    }
    int sumRootToLeaf(TreeNode* root) { return dfs(root, 0); }
};