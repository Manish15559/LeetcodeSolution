class Solution {
public:
    int bestClosingTime(string customers) {
        int tot=0;
        for(auto ch:customers) tot+=('N'==ch);

        int curr=0;
        int n=customers.size();
        int penalty=n+1;
        int hour=n+1;
        if(penalty>=(tot+curr)){
                penalty=tot+curr;
                hour=n;
            }
        for(int i=n-1;i>=0;i--){
            if(customers[i]=='Y') curr++;
            else tot--;
            if(penalty>=(tot+curr)){
                penalty=tot+curr;
                hour=i;
            }

        }


        return hour;


    }
};