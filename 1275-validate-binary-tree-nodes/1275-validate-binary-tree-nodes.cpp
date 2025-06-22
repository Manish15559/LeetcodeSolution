class Solution {
public:
struct TreeNode{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int val){
        data = val;
        left=right=NULL;
    }
   
};
bool dfs(TreeNode *node,vector<bool>&visited){
    visited[node->data]=true;
  
    if(node->left){
        if(visited[node->left->data]==1||dfs(node->left,visited)==false) return false;
        
        
    }
    if(node->right){
        if(visited[node->right->data]==1||dfs(node->right,visited)==false) return false;
       
        
    }
    return true;
}
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        
        map<int,TreeNode*>mp;
        unordered_set<TreeNode *>st;
        for(int i=0;i<n;i++){
            mp[i]=new TreeNode(i);
            st.insert(mp[i]);
        }
        

        for(int i=0;i<n;i++){
            if(leftChild[i]!=-1) {
                mp[i]->left=mp[leftChild[i]];
             if(st.find(mp[leftChild[i]])!=st.end()) st.erase(mp[leftChild[i]]);
            }
            if(rightChild[i]!=-1) {
                mp[i]->right=mp[rightChild[i]];
                if(st.find(mp[rightChild[i]])!=st.end()) st.erase(mp[rightChild[i]]);
            }
        }
        if(st.size()!=1) return false;
        TreeNode *root= *st.begin();

        vector<bool>visited(n,false);

        bool f=dfs(root,visited);
        if(f==false) return false;
        for(auto it:visited){
            if(it==false) return false;
        }
        return true;
        
    }
};