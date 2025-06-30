class Solution {
public:
int find(int num,int digit,int rep){
    cout<<digit<<" "<<rep<<endl;
    
    if(digit==-1) return num;

    int result=0;
    int  mul=1;
    while(num>0){
        int digi=num%10;
        if(digit==digi) digi=rep;
        num/=10;
        result=result+(mul*digi);
        mul*=10;
    }
   
    return result;
}
    int maxDiff(int num) {

        int ch1 = -1;
        int ch2 = -1;
        bool f=false;
        string s= to_string(num);

        if(s[0]!='1') {
            ch1=s[0]-'0';
            f=true;
        }

        for(int i=0;i<s.size();i++){
            if(s[i]!='1'&&s[i]!='0'&&ch1==-1) ch1=s[i]-'0';
            if(s[i]!='9'&&ch2==-1) ch2=s[i]-'0'; 
        }
       

        int mini=find(num,ch1,f?1:0);
        int maxi=find(num,ch2,9);

        return (maxi-mini);
        
    }
};