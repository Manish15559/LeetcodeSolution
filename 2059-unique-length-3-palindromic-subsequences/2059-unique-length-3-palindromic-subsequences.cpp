class Solution {
public:
    int countPalindromicSubsequence(string s) {

        int n=s.size();
        vector<int>rev(26,0);
        for(auto it:s) rev[(it-'a')]++;
        vector<int>pref(26,0);
        vector<vector<int>>arr(26,vector<int>(26,0));
        int ans=0;
        for(int i=0;i<n;i++){
            char ch=s[i];
            rev[(ch-'a')]--;
            for(int j=0;j<26;j++) {
                if(arr[(ch-'a')][j]) continue;
                ans+=((rev[j]>0&&pref[j]>0));
                arr[(ch-'a')][j]=((rev[j]>0&&pref[j]>0));
            }

            pref[(ch-'a')]++;

        }
        return ans;
    }
};