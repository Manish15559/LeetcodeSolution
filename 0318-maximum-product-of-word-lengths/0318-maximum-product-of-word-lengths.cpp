class Solution {
public:
    int maxProduct(vector<string>& words) {

        int n=words.size();
        vector<int>arr(n,0);
        vector<int>cnt(n,0);

        for(int i=0;i<n;i++){
            for(auto ch:words[i]){
                cnt[i]++;
                int bit=ch-'a';
                arr[i]=(arr[i]|(1<<bit));
            }
        }
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]&arr[j]) continue;
                ans=max(ans,(cnt[i]*cnt[j]));
            }
        }

        return ans;
        
    }
};