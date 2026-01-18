class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        unordered_map<char,int>required;
        for(auto ch:word2) required[ch]++;
        int totReq=word2.size();
        unordered_map<char,int>current;
        long long ans=0;
        int left=0;
        for(int right=0;right<word1.size();right++){
            char ch=word1[right];
            if(current[ch]<required[ch]) totReq--;
            current[ch]++;
            while(totReq==0&&current[word1[left]]>required[word1[left]]){
                current[word1[left]]--;
                left++;
            }
            if(totReq==0){
                ans+=(left+1);
            }
        }

        return ans;
        
    }
};