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
TreeNode *lcs(TreeNode *node, int startValue, int destValue){
    if(node==NULL||node->val==startValue||node->val==destValue){
        return node;
    }
    TreeNode *l=lcs(node->left,startValue,destValue);
    TreeNode *r=lcs(node->right,startValue,destValue);
    if(l==NULL) return r;
    else if(r==NULL) return l;
    return node;
}
bool helper1(TreeNode *node,int startValue,string &ans){
    if(node==NULL){
        return false;
    }
    if(node->val==startValue) return true;
    ans.push_back('U');
    if(helper1(node->left,startValue,ans)==true) return true;
    if(helper1(node->right,startValue,ans)==true) return true;
    ans.pop_back();
    return false;

}
bool helper2(TreeNode *node,int destValue,string &ans){
    if(node==NULL){
        return false;
    }
    if(node->val==destValue) return true;
    ans.push_back('L');
    if(helper2(node->left,destValue,ans)==true) return true;
    ans.pop_back();
    ans.push_back('R');
    if(helper2(node->right,destValue,ans)==true) return true;
    ans.pop_back();
    return false;

}
    string getDirections(TreeNode* root, int startValue, int destValue) {

        TreeNode *ansector=lcs(root,startValue,destValue);
        string ans="";
        helper1(ansector,startValue,ans);
        helper2(ansector,destValue,ans);
return ans;
        
    }
};