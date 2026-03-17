class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int col=0;col<m;col++){
            for(int row=1;row<n;row++){
                if(matrix[row][col]==0) continue;
                matrix[row][col]+=matrix[row-1][col];

            }
        }
        int ans=0;
        for(int row=0;row<n;row++){
            sort(matrix[row].begin(),matrix[row].end());
            // int value=0;
            for(int col=m-1;col>=0;col--){
                ans=max(ans,((m-col)*matrix[row][col]));
            }
            // cout<<ans<<endl;
        }
        return ans;
        
    }
};