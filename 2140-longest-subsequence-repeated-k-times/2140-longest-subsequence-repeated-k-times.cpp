class Solution {
public:
bool isPossible(string &s,string &curr,int k){
    int cnt=0;
    int idx=0;
    for(auto it:s){
        
        if(it==curr[idx]) idx++;
        if(idx==curr.size()){
            cnt++;
            idx=0;
        }

    }
    return cnt>=k;
}
    string longestSubsequenceRepeatedK(string s, int k) {

        vector<int>freq(26,0);
        for(auto it:s) freq[it-'a']++;

        string potentialCh ="";
        for(int i=25;i>=0;i--){
            if(freq[i]>=k) potentialCh.push_back('a'+i);
        }
        queue<string> q;
        for( char ch: potentialCh) q.push(string(1,ch));

        string ans="";
        while(!q.empty()){
            string curr=q.front();
            q.pop();
            if(curr.size()>ans.size()) ans=curr;

            for(char ch:potentialCh){
                string next=curr+ch;
                if(isPossible(s,next,k)) q.push(next);
            }
        }
        return ans;

        
    }
};