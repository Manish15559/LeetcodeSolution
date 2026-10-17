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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map < int, map<int, multiset<int>>> mp;      // vertical, level,  value
        queue < pair < int, pair<int, TreeNode*>>> q; // vertical, level, value;
        mp[0][0].insert(root->val);
        q.push({0, {0, root}});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int vertical = it.first;
            int horizontal = it.second.first;
            TreeNode* currNode = it.second.second;
            if (currNode->left) {
                q.push({(vertical - 1), {(horizontal + 1), currNode->left}});
                mp[(vertical - 1)][(horizontal + 1)].insert(currNode->left->val);
            }
            if (currNode->right) {
                q.push({(vertical + 1), {(horizontal + 1), currNode->right}});
                mp[(vertical + 1)][(horizontal + 1)].insert(currNode->right->val);
            }
        }
        vector<vector<int>> ans;
        for (auto it : mp) {
            vector<int> curr;
            for (auto iter : it.second) {
                for(auto iter2:iter.second){
                curr.push_back(iter2);
                }
            }
            ans.push_back(curr);
        }
        return ans;
    }
};