class Solution {
public:
bool comp(char a, char b, vector<vector<int>> &rank) {
    int m = rank[0].size();
    for (int i = 0; i < m; ++i) {
        if (rank[a - 'A'][i] != rank[b - 'A'][i])
            return rank[a - 'A'][i] > rank[b - 'A'][i]; 
    }
    return a < b; 
}
    string rankTeams(vector<string>& votes) {

        int n = votes.size();
        int m = votes[0].size();

        vector<vector<int>>arr(26,vector<int>(m,0));


        for(int i=0;i<n;i++){  
            for(int j=0;j<m;j++){
                arr[(votes[i][j]-'A')][j]++;
            }
        }

        vector<bool>present(26,0);
        for(auto ch:votes[0]) present[(ch-'A')]=1;
        string ans="";
        for(char ch='A';ch<='Z';ch++) if(present[(ch-'A')])  ans.push_back(ch);

          sort(ans.begin(), ans.end(), [&](char a, char b) {
            for (int i = 0; i < m; ++i) {
                if (arr[a - 'A'][i] != arr[b - 'A'][i])
                    return arr[a - 'A'][i] > arr[b - 'A'][i]; // more votes higher
            }
            return a < b; // alphabetical tie-break
        });

        return ans;

       

        

       
        
    }
};