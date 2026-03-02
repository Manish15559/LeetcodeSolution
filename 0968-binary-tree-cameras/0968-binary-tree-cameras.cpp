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

     // 0 => no camera is covering
     // 1 => camera is covering
     // 2 => has a camera
     bool isLeaf(TreeNode *node) {
        return (node->left==NULL)&&(node->right==NULL);
     }
     int isMonitor(TreeNode *node,int &ans){
        if(node==NULL) return 1;
        int leftSubtree = isMonitor(node->left,ans);
        int rightSubtree= isMonitor(node->right,ans);
        if(leftSubtree==0||rightSubtree==0) {
            ans++;
            return 2;
        }
        if(leftSubtree==2||rightSubtree==2){
            return 1;
        }
        return 0;
     }
    int minCameraCover(TreeNode* root) {
        int count=0;
        if(isMonitor(root,count)==0) count++;
        return count;
    }
};