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
    TreeNode* helper(int preLeft, int preRight, int inLeft, int inRight,
                     vector<int>& preorder, vector<int>& inorder) {

        if (inLeft > inRight)
            return NULL;

        int val = preorder[preLeft];
        int idx = inLeft;
        while (idx < inRight && inorder[idx] != val)
            idx++;
        int leftLen = idx - inLeft;
        int rightLen = inRight - idx;
        TreeNode* node = new TreeNode(val);
        node->left = helper(preLeft + 1, preLeft + leftLen, inLeft, idx - 1,
                            preorder, inorder);
        node->right = helper(preLeft + leftLen + 1, preRight, idx + 1, inRight,
                             preorder, inorder);
                             return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        return helper(0, n - 1, 0, n - 1, preorder, inorder);
    }
};