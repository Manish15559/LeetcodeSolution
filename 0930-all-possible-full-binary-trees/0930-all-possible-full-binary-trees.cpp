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
    unordered_map<int,vector<TreeNode *>>dp;
    vector<TreeNode*> allPossibleFBT(int n) {
        if(dp.find(n)!=dp.end()) return dp[n];
        if(n%2==0) return {};
        vector<TreeNode *>res;
        if(n==1) {
            TreeNode *root= new TreeNode();
            res.push_back(root);
            return res;

        }
        for(int i=1;i<n-1;i+=2){
            vector<TreeNode *>left= allPossibleFBT(i);
            vector<TreeNode *>right= allPossibleFBT(n-1-i);
            for(auto l:left){
                for(auto r:right){
                    TreeNode *root= new TreeNode(0,l,r);
                    res.push_back(root);

                }
            }

        }

        return dp[n]=res;

       
        
    }
};