class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int count1=0;  //last is zero    count1=2, count2=0,  curr1=3, curr2=1
        int count2=0;
        for(auto it:s){
            if(it=='1'){
                int curr1=count1+1;
                int curr2=min(count1,count2);
                count1=curr1;
                count2=curr2;

            }
            else{
                int curr1=count1;
                int curr2=1+min(count1,count2);
                count1=curr1;
                count2=curr2;
            }

        }

        return min(count1,count2);
        
    }
};