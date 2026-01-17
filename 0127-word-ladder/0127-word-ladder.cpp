class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>unvisited;
        for(auto it:wordList) unvisited.insert(it);
        if(unvisited.find(endWord)==unvisited.end()) return 0;
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){  //tc: o(wordList.size()*len*26) sc: o(n*len)
            string str=q.front().first;
            int path=q.front().second;
            q.pop();
            for(int idx=0;idx<str.size();idx++){
                char character=str[idx];
                for(char ch='a';ch<='z';ch++){
                    str[idx]=ch;
                    if(unvisited.find(str)!=unvisited.end()){
                        if(str==endWord) return (path+1);
                        q.push({str,(path+1)});
                        unvisited.erase(str);
                    }
                }
                str[idx]=character;
            }
        }

        return 0;
        
    }
};