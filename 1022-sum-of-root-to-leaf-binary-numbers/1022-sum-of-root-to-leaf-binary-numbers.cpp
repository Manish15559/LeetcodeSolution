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
    void dfs(TreeNode* node, int curr, int& ans) {
        curr = 2 * curr;
        if (node->val)
            curr++;
        if (isLeaf(node)) {

            ans += curr;
            return;
        }

        if (node->left != NULL) {

            dfs(node->left, curr, ans);
        }
        if (node->right != NULL) {
            dfs(node->right, curr, ans);
        }
    }
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;

        dfs(root, 0, ans);
        return ans;
    }
};