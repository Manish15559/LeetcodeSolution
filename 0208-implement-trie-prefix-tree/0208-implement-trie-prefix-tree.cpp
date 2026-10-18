class Node {
    Node* links[26];
    bool flag;

public:
    bool containKey(char ch) { return links[(ch - 'a')] != NULL; }
    void put(char ch, Node* node) { links[(ch - 'a')] = node; }
    Node* get(char ch) { return links[ch - 'a']; }
    bool isEnd() { return flag; }
    void setEnd() { flag = true; }
};

class Trie {
public:
    Node* root;
    Trie() { root = new Node(); }

    void insert(string word) {
        Node* curr = root;
        for (auto ch : word) {

            if (!curr->containKey(ch)) {
                curr->put(ch, new Node());
            }
            curr = curr->get(ch);
        }
        curr->setEnd();
    }

    bool search(string word) {
        Node* curr = root;
        for (auto ch : word) {

            if (!curr->containKey(ch)) {
                return false;
            }
            curr = curr->get(ch);
        }
        return curr->isEnd();
    }

    bool startsWith(string prefix) {
        Node* curr = root;
        for (auto ch : prefix) {

            if (!curr->containKey(ch)) {
                return false;
            }
            curr = curr->get(ch);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */