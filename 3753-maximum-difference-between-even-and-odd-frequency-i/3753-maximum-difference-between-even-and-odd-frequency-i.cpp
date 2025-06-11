class Solution {
public:
    int maxDifference(string s) {
        unordered_map<int,int>f;

        for(auto it:s) f[it]++;

        int smallestOdd=1e9, smallestEven=1e9, largestOdd=-1, largestEven=-1;


        for(auto it:f){
            if(it.second%2){
                smallestOdd=min(smallestOdd,it.second);
                largestOdd=max(largestOdd,it.second);
            }
            else{
                smallestEven=min(smallestEven,it.second);
                largestEven=max(largestEven,it.second);
            }
        }

        return (largestOdd-smallestEven);


        
    }
};