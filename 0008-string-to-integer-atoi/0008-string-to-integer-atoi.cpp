class Solution {
public:
    int myAtoi(string s) {

       if(s.size()==0) return 0;
       int n=s.size();

       bool isPositive = true;

      
       int left=0;
       int right =n;

       while(left<n&&s[left]==' ') left++;
       cout<<left<<endl;

        if(s[left]=='-') isPositive=false;
       bool f=true; //this track whether i have included any number in final string or not
       int init=left;
       for(int idx=left;idx<n;idx++){
        if(idx==init&&(s[idx]=='+'||s[idx]=='-')) {
            left=idx+1;
            continue;
        }
        if(f&&(s[idx]=='0')) left=idx+1;
        else if ('0'<=s[idx]&&s[idx]<='9'){
            f=false;
        }
        else{
            right=idx;
            break;
        }
       }

        long long number=0;
        long long mul=1;
        cout<<left<<" "<<right;
        if((right-left)>10){
            if(isPositive) return INT_MAX;
            else return INT_MIN;
        }

        for(int idx=right-1;idx>=left;idx--){

            number =number + ((s[idx]-'0')*(mul));
            mul*=10;

        }
        number*=(isPositive?1:-1);
        if(INT_MIN<=number&&number<=INT_MAX) return number;


        if(isPositive) return INT_MAX;
            else return INT_MIN;

       }

        
    
};