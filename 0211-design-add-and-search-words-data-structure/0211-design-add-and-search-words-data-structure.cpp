class Node {
    Node* links[26];
    bool isEnd;

public:
    Node() { isEnd = false; 
    for(int i=0;i<26;i++) links[i]=NULL;
    }
    void put(char ch, Node* node) { links[(ch - 'a')] = node; }
    bool containsKey(char ch) { 
       
        
        return links[ch - 'a'] != NULL; }
    Node* get(char ch) { return links[(ch - 'a')]; }

    void setEnd() { isEnd = true; }
    bool whetherEnd() { return isEnd; }
};

class WordDictionary {
public:
    Node* root;

    WordDictionary() { root = new Node(); }

    void addWord(string word) {

        Node* node = root;
        for (char ch : word) {
          
            if (node->containsKey(ch) == false) {
                Node* newNode = new Node();
                node->put(ch, newNode);
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    bool helper(int idx, Node* node, string& str) {
        if (idx == str.size()) {
            return node->whetherEnd();
        }
        if (str[idx] =='.') {

            for (char ch ='a'; ch <= 'z'; ch++) {
                if (node->containsKey(ch)) {
                    if (helper(idx + 1, node->get(ch), str) == true)
                        return true;
                }
            }

        } else {
            char ch = str[idx];
            if (node->containsKey(ch)) {
                if (helper(idx + 1, node->get(ch), str) == true)
                    return true;
            }
        }
        return false;
    }
    bool search(string word) {
        if (word.size() == 0)
            return false;
        Node* node = root;

        return helper(0, node, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
