class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>countChar(26,0);  //in current window;
        int n=s.size();
        vector<int>value(n+1,0);

        int maxLength=1;
        int maxChar=0; //in current window;

        int left=0;
        for(int right=0;right<s.size();right++){
            int key=s[right]-'A';
            countChar[key]++;
            if(countChar[key]>1) value[(countChar[key]-1)]--;
            value[countChar[key]]++;
            maxChar=max(maxChar,countChar[key]);
            int tot=right-left+1;
            while(k<(tot-maxChar)&&left<right){
                int key=s[left]-'A';
                tot--;
                value[countChar[key]]--;
                countChar[key]--;
                value[countChar[key]]++;
                if(value[maxChar]==0) maxChar--;
                left++;

            }
            maxLength=max((right-left+1),maxLength);

        }

        return maxLength;

        
    }
};