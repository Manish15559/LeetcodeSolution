class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n=players.size();
        int m=trainers.size();
        int idx1=0;
        int idx2=0;
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int cnt=0;
        while(idx1<n&&idx2<m){
            if(players[idx1]<=trainers[idx2]){
                cnt++;
                idx1++;
                idx2++;
            }
            else idx2++;
        }
        return cnt;
    }
};