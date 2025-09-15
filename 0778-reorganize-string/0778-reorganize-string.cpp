class Solution {
public:
    string reorganizeString(string s) {

        // count of each word => max > total+1-max

    int cnt[26]={0};
    int n=s.size();
    for(int i=0;i<n;i++){
        cnt[s[i]-'a']++;
    }
    vector<pair<int,int>>arr;
    for(int i=0;i<26;i++) if(cnt[i]>0) arr.push_back({cnt[i],i});

    sort(arr.begin(),arr.end());
    reverse(arr.begin(),arr.end());

    if((2*arr[0].first)>(n+1)) return "";
    
    queue<char>q;
   
    for(auto it:arr){
    int cn=it.first;
    char ch= char('a'+it.second);
    // cout<<ch<<endl;
    while(cn--){
        if(!q.empty()){
            char c=q.front();
            q.pop();
            q.push(ch);
            q.push(c);
        }
        else{
            q.push(ch);
        }
    }
    }

    string ans="";
    while(!q.empty()){
        ans.push_back(q.front());
        q.pop();

    
    }

    return ans;

    }
 
        
    
};