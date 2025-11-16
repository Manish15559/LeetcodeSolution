class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int test=minutesToTest/minutesToDie;
        int pigs=0;
        int outcome=1;
        while(outcome<buckets){
            pigs++;
            outcome*=(test+1);

        }

        return pigs;
        
    }
};