class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0,difict=0,balance=0,n=gas.size();

        for(int i=0;i<n;i++){
            balance+=(gas[i]-cost[i]);
            if(balance<0){
                difict+=balance;
                balance=0;
                start=i+1;
            }
        }
        if(difict+balance>=0){
            return start;
        }
        return -1;
        
    }
};