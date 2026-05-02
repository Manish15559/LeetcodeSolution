class Node {
public:
    Node* links[2];
};
class Trie {
    Node* root;
    public:
    Trie(){ root = new Node(); }

    void insert(int num) {
        int pos = 30;
        Node* curr = root;
        for (int pos = 30; pos >= 0; pos--) {
            int bit = (num >> pos) & 1;
            if (curr->links[bit] == NULL) {
                Node* nextNode = new Node();
                curr->links[bit] = nextNode;
            }
            curr = curr->links[bit];
        }
    }

    int findMax(int num) {
        int pos = 30;
        int res = 0;
        Node* curr = root;
        for (int pos = 30; pos >= 0; pos--) {
            int bit = (num >> pos) & 1;

            if (curr->links[(!bit)] == NULL) {
                curr = curr->links[bit];
            } else {
                res |= (1 << pos);
                curr = curr->links[(!bit)];
            }
        }
        return res;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {

        Trie* obj = new Trie();
        int ans = 0;
        for (auto it : nums) {
            obj->insert(it);
            ans = max(ans, (obj->findMax(it)));
        }
        return ans;
    }
};