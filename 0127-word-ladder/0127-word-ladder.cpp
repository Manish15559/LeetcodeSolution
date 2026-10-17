class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> unVisitedWord;
        bool flag = false;

        for (auto it : wordList) {
            if (it != beginWord)
                unVisitedWord.insert(it);
            if (it == endWord)
                flag = true;
        }
        if (!flag)
            return 0;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while (!q.empty()) {
            string word = q.front().first;
            int operation = q.front().second;
            q.pop();
            int length = word.size();
            for (int i = 0; i < length; i++) {
                char character = word[i];
                for (int ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (unVisitedWord.find(word) != unVisitedWord.end()) {
                        if (word == endWord)
                            return (operation + 1);
                        q.push({word, (operation + 1)});
                        unVisitedWord.erase(word);
                    }
                }
                word[i] = character;
            }
        }

        return 0;
    }
};