class Solution {
public:
    int myAtoi(string s) {

        long long num=0;
        bool isNegative=false;
        bool isDigitSeen=false;
        bool isSignSeen=false;
        for(int i=0;i<s.size();i++){

            //suppose a space is appear at index i

            if(isDigitSeen==false&&isSignSeen==false&&s[i]==' ') continue;
            //supppose a sign is appear at index i
            else if(isDigitSeen==false&&isSignSeen==false&&(s[i]=='+'||s[i]=='-')){
                if(s[i]=='-') isNegative=true;
                isSignSeen=true;
            }
            else if('0'<=s[i]&&s[i]<='9'){
                isDigitSeen =true;
                num= (num*10)+(s[i]-'0');
                if(isNegative&&(-1*num)<INT_MIN) return INT_MIN;
                else if(!isNegative&&num>INT_MAX) return INT_MAX;
            }
            else{
                break;
            }
        }


        return isNegative?(-1*num):num;
    

      

       }

        
    
};