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
bool helper1(TreeNode *node,int start,string &ans){
    if(node==NULL) return false;
    if(node->val==start) return true;
    ans.push_back('U');
    if(helper1(node->left,start,ans)==true) return true;
   
    if(helper1(node->right,start,ans)==true) return true;
    ans.pop_back();
    return false;
}
bool helper2(TreeNode *node,int dest,string &ans){
    if(node==NULL) return false;
    if(node->val==dest) return true;
    ans.push_back('L');
    if(helper2(node->left,dest,ans)==true) return true;
    ans.pop_back();
     ans.push_back('R');
    if(helper2(node->right,dest,ans)==true) return true;
    ans.pop_back();
    return false;
}
    string getDirections(TreeNode* root, int startValue, int destValue) {


        TreeNode * ancestor=lcs(root,startValue,destValue);

        string ans="";
        helper1(root,startValue,ans);
        helper2(root,destValue,ans);
        return ans;

        
    }
};