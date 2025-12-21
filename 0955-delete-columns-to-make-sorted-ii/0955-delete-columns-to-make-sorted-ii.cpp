class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m=strs[0].size();
        int n=strs.size();
        vector<int>isEqual(n,1);
        // cout<<n<<" "<<m<<endl;
        int ans=0;
       for(int i=0;i<m;i++){
        bool isRemove=false;
        for(int j=1;j<n;j++){
            if(!isEqual[j]) continue;
            if(strs[j][i]<strs[j-1][i]) {
               isRemove=true;
               break;
            }
        }
        if(isRemove) ans++;
        else{
            for(int j=1;j<n;j++){
           if(strs[j][i]>strs[j-1][i]) {
              isEqual[j]=0;
            }
               
            }
        }
    //    for(auto it:isEqual) cout<<it<<" ";
    //    cout<<endl;

       }

       return ans;
    }
};