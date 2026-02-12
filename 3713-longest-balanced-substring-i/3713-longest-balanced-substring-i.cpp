class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size();
        vector<vector<int>>pref(n+1,vector<int>(26,0));
        // int ans=0;

        for(int i=0;i<n;i++){
            pref[i+1]=pref[i];
            pref[i+1][s[i]-'a']++;
        }
        int ans=1;
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=0;j--){
                bool f=true;
                int x=-1;
                for(int ch=0;ch<26;ch++){
                    int curr=(pref[i][ch]-pref[j][ch]);
                    if(curr==0) continue;

                    if(x==-1){
                        x=curr;
                    }
                    else if(x!=curr){
                        f=false;
                        break;
                    }
                }
                if(f) ans=max(ans,(i-j));
            }
        }
        return ans;
        
    }
};