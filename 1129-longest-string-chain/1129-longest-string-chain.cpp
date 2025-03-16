class Solution {
public:
static bool customSort(string &a,string &b){
    return a.size()<b.size();
}

bool check(string &sucessor,string &predecessor){
    bool f=true;
    int idx1=0;
    int idx2=0;
    int n=sucessor.size();
    int m=predecessor.size();
    while(idx1<n&&idx2<m){
        if(sucessor[idx1]==predecessor[idx2]){
            idx1++;
            idx2++;
        }
        else if(f){
            idx1++;
            f=false;
        }
        else{
            return false;
        }
    }
    if(f) idx1++;
    if(idx2==m&&idx1==n) return true;
    return false;
}
    int longestStrChain(vector<string>& words) {

        sort(words.begin(),words.end(),customSort);

        int n=words.size();
        vector<int>dp(n,1);

        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(check(words[i],words[j])){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
        }

        int result=*max_element(dp.begin(),dp.end());

        return result;


        
    }
};