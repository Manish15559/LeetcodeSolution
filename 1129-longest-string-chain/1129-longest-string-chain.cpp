class Solution {
public:
static bool customSort(string &a,string &b){
    return a.size()<b.size();
}

    int longestStrChain(vector<string>& words) {

        sort(words.begin(),words.end(),customSort);

        int n=words.size();
       unordered_map<string,int>dp;

        for(int i=0;i<n;i++){
            int sz=words[i].size();
            int curr_ans=1;
            for(int idx=0;idx<sz;idx++){
                string curr=words[i].substr(0,idx)+words[i].substr(idx+1,(sz-idx));
                
                if(dp.find(curr)!=dp.end()){
                    curr_ans=max(curr_ans,dp[curr]+1);

                }
            }
            dp[words[i]]=curr_ans;
            
        }

        int result=1;
        for(auto it:dp) result=max(result,it.second);

        return result;


        
    }
};