class Solution {
public:
    int numSteps(string s) {
        int idx=0;
        reverse(s.begin(),s.end());
        int count=0;
        while(idx<(s.size()-1)){
            
            count++;
            if(s[idx]=='0'){
                idx++;

            }
            else{
                int j=idx;
                while(j<s.size()&&s[j]=='1'){
                    s[j]='0';
                    j++;

                }

                if(j<s.size()) s[j]='1';
                else s.push_back('1');
            }
            cout<<s<<" "<<idx<<endl;
        }

        return count;
        
    }
};