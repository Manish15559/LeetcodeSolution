class Solution {
public:
    int numberOfSubstrings(string s) {

        int n=s.size();
        int cnt[3]={0};
        int c=0;
        //0 a 1 b 2 c

        int left=0;
        long long tot=((long long)n*(n+1))/2;

        for(int right=0;right<n;right++){
            int ch=s[right]-'a';
            if(cnt[ch]==0) c++;
            cnt[ch]++;
            while(c>2&&left<=right){
                int ch=s[left]-'a';
                cnt[ch]--;
                if(cnt[ch]==0) c--;
                left++;
            }
            tot-=(right-left+1);
        }

        return tot;
        
    }
};