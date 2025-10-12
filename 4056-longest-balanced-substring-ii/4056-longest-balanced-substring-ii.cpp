class Solution {
public:
int onlyOnerCharacter(string &s){
    int ans=1;
    int cnt=1;
    for(int i=1;i<s.size();i++){
        if(s[i]==s[i-1]) cnt++;
        else cnt=1;
        ans=max(ans,cnt);
    }
    return ans;
}
int withTwoCharacter(string &s,char plusCharacter,char subtractCharacter,char ignoreCharacter){
    int n=s.size();
    unordered_map<int,int>pref;
    int ans=0;
    pref[0]=-1;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]==ignoreCharacter){
            pref.clear();
            pref[0]=i;
            cnt=0;
        }
        else{
            if(s[i]==plusCharacter) cnt++;
            else cnt--;
            if(pref.find(cnt)!=pref.end()) ans=max(ans,(i-pref[cnt]));
            else pref[cnt]=i;

        }
    }
    return ans;
   
}

int withThreeCharacter(string &s){
    map<pair<int,int>,int>mp;
        mp[{0,0}]=-1;
        int cnt1=0;
        int cnt2=0;
        int ans=1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='b') {
                cnt1++;
                cnt2++;
            }
            else if(s[i]=='a') cnt1--;
            else cnt2--;
            if(mp.find({cnt1,cnt2})!=mp.end()){
                // cout<<cnt1<<" "<<cnt2<<" "<<i<<endl;
                ans=max(ans,(i-mp[{cnt1,cnt2}]));
            }
            else{
                mp[{cnt1,cnt2}]=i;
            }
        }
        return ans;

}
    int longestBalanced(string s) {

       int ans=0;
       ans=onlyOnerCharacter(s);
       ans=max(ans,withTwoCharacter(s,'a','b','c'));
       ans=max(ans,withTwoCharacter(s,'a','c','b'));
       ans=max(ans,withTwoCharacter(s,'c','b','a'));
       ans=max(ans,withThreeCharacter(s));


       return ans;

        
        
    }
};