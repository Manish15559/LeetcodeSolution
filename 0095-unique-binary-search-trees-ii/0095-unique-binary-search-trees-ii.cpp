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
    vector<TreeNode*> buildBst(int l, int r) {
        if (l > r)
            return {NULL};

        vector<TreeNode*> arr;
        for (int i = l; i <= r; i++) {

            vector<TreeNode*> left = buildBst(l, i - 1);
            vector<TreeNode*> right = buildBst(i + 1, r);

            for (auto &lh : left) {
                for (auto &rh : right) {
                    TreeNode* head = new TreeNode(i);
                    head->left = lh;
                    head->right = rh;
                    arr.push_back(head);
                }
            }
        }
        return arr;
    }
    vector<TreeNode*> generateTrees(int n) { return buildBst(1, n); }
};