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
    void preorderTraversal(TreeNode* node, vector<TreeNode*>& preorderNodes) {
        if (node == NULL)
            return;
        preorderNodes.push_back(node);
        preorderTraversal(node->left, preorderNodes);
        preorderTraversal(node->right, preorderNodes);
        return;
    }
    void flatten(TreeNode* root) {
        if (root == NULL)
            return;
        vector<TreeNode*> preorderNodes;
        preorderTraversal(root,preorderNodes);
        int n=preorderNodes.size();
        for (int idx = 0; idx < preorderNodes.size(); idx++) {
            TreeNode* node = preorderNodes[idx];
            node->left = NULL;
            if (idx < (n - 1))
                node->right = preorderNodes[idx + 1];
            else
                node->right = NULL;
        }
    }
};