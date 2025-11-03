class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        int tot=0;
        for(auto time:neededTime) tot+=time;
        char prev = colors[0];
        int curr = neededTime[0];
        int rem=0;
        for(int i=1;i<n;i++){
            if(colors[i]!=prev){
                rem+=curr;
                curr=neededTime[i];

            }
            else{
                curr=max(curr,neededTime[i]);
            }
            prev=colors[i];
        }
        rem+=curr;

        return (tot-rem);

        
    }
};