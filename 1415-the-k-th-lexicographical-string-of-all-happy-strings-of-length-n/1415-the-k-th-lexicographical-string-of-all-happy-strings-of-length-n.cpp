class Solution {
public:
    string findKthString(int idx,char prev,int n,int &count,int k){
        if(idx==n){
            count++;
           return "";
        }
        for(char ch='a';ch<='c';ch++){
            if(ch==prev) continue;
            string s = findKthString(idx+1,ch,n,count,k);
            if(count==k) return ch+s;
        }

        return "";

    }
    string getHappyString(int n, int k) {
       int count=0;
        return findKthString(0,'d',n,count,k);
        
    }
};