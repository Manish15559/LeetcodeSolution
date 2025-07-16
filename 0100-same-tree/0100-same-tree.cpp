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
bool check(TreeNode* node1, TreeNode* node2){
     if(node1==NULL&&node2==NULL){
        return true;
    }
    if(node1==NULL){
        return false;
    }
    if(node2==NULL){
        return false;
    }
    if(node1->val!=node2->val){
        return false;
    }
   
    if(check(node1->left,node2->left)==false){
        return false;
    }
    if(check(node1->right,node2->right)==false){
        return false;
    }


    return true;
}
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return check(p,q);
        
    }
};