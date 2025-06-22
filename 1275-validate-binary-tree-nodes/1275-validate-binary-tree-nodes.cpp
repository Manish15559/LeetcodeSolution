class Solution {
public:
  bool dfs(int node, vector<int>& leftChild, vector<int>& rightChild,unordered_set<int>&seen){
    seen.insert(node);
    if(leftChild[node]!=-1){
        if(seen.find(leftChild[node])!=seen.end()) return false;
        seen.insert(leftChild[node]);
        if(dfs(leftChild[node],leftChild,rightChild,seen)==false) return false;
    }
    if(rightChild[node]!=-1){
        if(seen.find(rightChild[node])!=seen.end()) return false;
        seen.insert(rightChild[node]);
        if(dfs(rightChild[node],leftChild,rightChild,seen)==false) return false;
    }
    return true;
    
  }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {

        unordered_set<int>st;
        for(auto it:leftChild) st.insert(it);
        for(auto it:rightChild) st.insert(it);

        int root=-1;
        for(int i=0;i<n;i++) {
            if(st.find(i)==st.end()){
                root=i;
                break;
            }
        }
        if(root==-1) return false;
        unordered_set<int>seen;

       
        bool valid=dfs(root,leftChild,rightChild,seen);
       
         return valid & (seen.size()==n);
        
    }
};