class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans=0;
        while(num1<=num2){
            string a=to_string(num1);
            num1++;
            for(int idx=1;idx<(size(a)-1);idx++){
                int op1=(a[idx-1]<a[idx]&&a[idx]>a[idx+1]);
                int op2=(a[idx-1]>a[idx]&&a[idx]<a[idx+1]);
                ans+=(op1+op2);

            }
        }
        return ans;
        
    }
};