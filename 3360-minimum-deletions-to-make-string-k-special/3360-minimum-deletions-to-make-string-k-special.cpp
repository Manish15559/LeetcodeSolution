class Solution {
public:
    int minimumDeletions(string word, int k) {

    vector<int>ch(26,0);
    for(auto it:word) ch[it-'a']++;
    vector<int>arr;
    for(auto it:ch) if(it>0) arr.push_back(it);
    sort(arr.begin(),arr.end());
    int m=arr.size();
  
    vector<int>pref(m+1,0);
    for(int i=0;i<m;i++){
        pref[i+1]=arr[i]+pref[i];
    }
    int ans=1e9;
   
   for(int i=0;i<m;i++){
    int idx=upper_bound(arr.begin(),arr.end(),(arr[i]+k))-arr.begin();
    int val=pref[idx]-pref[i];
    val+=(m-idx)*(arr[i]+k);
    ans=min(ans,(pref[m]-val));

    
   }
   return ans;
        
    }
};