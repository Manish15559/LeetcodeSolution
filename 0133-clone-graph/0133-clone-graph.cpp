/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node * dfs(Node *node,unordered_map<int,Node*>&mp){
        int value=node->val;
        Node *newNode = new Node(value);
        mp[value] = newNode;

        for(auto it:node->neighbors){
            int adjValue = it->val;
            if(mp.find(adjValue)==mp.end()){
                newNode->neighbors.push_back(dfs(it,mp));
            }
            else{
                newNode->neighbors.push_back(mp[adjValue]);
            }


        }

        return newNode;
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        unordered_map<int,Node *>mp;
        return dfs(node,mp);
        
    }
};