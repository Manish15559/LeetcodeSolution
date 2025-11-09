class Solution {
public:
    string rankTeams(vector<string>& votes) {

        int n = votes.size();
        int m = votes[0].size();

        vector<vector<int>>arr(26,vector<int>(m,0));


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[(votes[i][j]-'A')][j]++;
            }
        }

       

        string str ="";
        vector<int>done(26,1);
        for(auto it:votes[0]) done[(it-'A')]=0;
        for(int i=0;i<m;i++){
            vector<int>check(26,0);
            for(int j=0;j<m;j++){
                int mx=-1;
                for(int team=0;team<26;team++){
                    if(check[team]||done[team]) continue;
                    mx=max(mx,arr[team][j]);

                }
                // cout<<mx<<" ";
                for(int team=0;team<26;team++){
                   if(check[team]||done[team]) continue;
                   if(mx>arr[team][j]) check[team]=1;

                }
            }
            // cout<<endl;
            for(int team=0;team<26;team++){
                if(!done[team]&&!check[team]){
                    cout<<team<<endl;
                    done[team]=1;
                    str.push_back(('A'+team));
                    break;
                }
            }
        }

        return str;

       
        
    }
};