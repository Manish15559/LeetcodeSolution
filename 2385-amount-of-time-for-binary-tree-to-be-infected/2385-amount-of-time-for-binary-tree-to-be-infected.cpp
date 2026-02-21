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
    void dfs(TreeNode* node, TreeNode*& root, int start,
             unordered_map<TreeNode*, vector<TreeNode*>>& reverseEdge) {
        if (node->val == start)
            root = node;
        if (node->left) {
            reverseEdge[node->left].push_back(node);
            dfs(node->left, root, start, reverseEdge);
        }
        if (node->right) {
            reverseEdge[node->right].push_back(node);
            dfs(node->right, root, start, reverseEdge);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, vector<TreeNode*>> reverseEdge; // o(n+m)
        //    tc: o(n)+o(n)
        TreeNode* node;
        dfs(root, node, start, reverseEdge); // o(n)

        int ans = -1;
        queue<TreeNode*> q;               // o(n)
        unordered_set<TreeNode*> visited; // o(n)
        visited.insert(node);
        q.push(node);

        while (!q.empty()) {
            int sz = q.size();
            ans++;
            for (int i = 0; i < sz; i++) {
                TreeNode* curr = q.front();
               
                q.pop();
                for (auto it : reverseEdge[curr]) {
                    if (visited.find(it) == visited.end()) {
                        q.push(it);
                        visited.insert(it);
                    }
                }
                if (curr->left && visited.find(curr->left) == visited.end()) {
                    q.push(curr->left);
                    visited.insert(curr->left);
                }
                if (curr->right && visited.find(curr->right) == visited.end()) {
                    q.push(curr->right);
                    visited.insert(curr->right);
                }
            }
        }
        return ans;
    }
};