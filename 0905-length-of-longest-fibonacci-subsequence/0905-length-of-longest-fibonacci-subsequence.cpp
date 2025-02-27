class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,0));

        int mxLen=0;
        for(int curr=2;curr<n;curr++){
            int start=0;
            int end=curr-1;
            while(start<end){
                int sum=arr[start]+arr[end];
                if(sum>arr[curr]){
                    end--;

                }
                else if(sum<arr[curr]){
                    start++;
                }
                else{
                    dp[curr][end]=1+dp[end][start];
                    mxLen=max(mxLen,dp[curr][end]);
                    start++;
                    end--;
                }

            }
        }
        return mxLen==0?0:(mxLen+2);

               

    



        
    }
};