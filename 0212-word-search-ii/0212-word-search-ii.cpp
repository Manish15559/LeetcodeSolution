class Node {
public:
    Node* links[26];
    bool isEnd;

public:
    Node() {
        isEnd = false;
        for (int node = 0; node < 26; node++)
            links[node] = NULL;
    }
    bool containsKey(char ch) {
        int node = ch - 'a';
        return links[node] != NULL;
    }
    void put(char ch, Node* newNode) {
        int node = ch - 'a';
        links[node] = newNode;
    }
    Node* get(char ch) {
        int node = ch - 'a';
        return links[node];
    }
    bool whetherEnd() { return isEnd; }
    void setEnd() { isEnd = true; }
};

class Solution {
public:
    void insertWord(string& word, Node* root) {
        Node* node = root;
        for (auto ch : word) {
            if (!node->containsKey(ch)) {
                Node* newNode = new Node();
                node->put(ch, newNode);
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    bool isValid(int row, int col, int n, int m) {
        return row >= 0 && col >= 0 && row < n && col < m;
    }
    void dfs(int row, int col, string &str, unordered_set<string>& findWord,
             Node* node, vector<vector<char>>& board) {
               
        char ch = board[row][col];
        if (ch=='#'||!node->containsKey(ch))
            return;
        node = node->get(ch);
        str.push_back(ch);
        if (node->whetherEnd()) {
           
            if (findWord.find(str) == findWord.end())
                findWord.insert(str);
        }
        board[row][col] = '#';
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        for (int idx = 0; idx < 4; idx++) {
            int nrow = row + dx[idx];
            int ncol = col + dy[idx];
            if (!isValid(nrow, ncol, board.size(), board[0].size()))
                continue;
            dfs(nrow, ncol, str, findWord, node, board);
        }
        str.pop_back();
        board[row][col] = ch;
    }
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        Node* root = new Node();
        for (auto word : words) {
            insertWord(word, root);
        }
        string str;
        unordered_set<string> findWord;
        int n = board.size();
        int m = board[0].size();
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                dfs(row, col, str, findWord, root, board);
            }
        }
        vector<string> ans;
        for (auto word : findWord)
            ans.push_back(word);
        return ans;
    }
};