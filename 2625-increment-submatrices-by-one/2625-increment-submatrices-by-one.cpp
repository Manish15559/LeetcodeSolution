class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>arr(n,vector<int>(n,0));
        for(auto it: queries){  //o(q*n)
            int row1=it[0];
            int col1=it[1];
            int row2=it[2];
            int col2=it[3];
            for(int row=row1;row<=row2;row++){
                arr[row][col1]++;
                if((col2+1)<n) arr[row][col2+1]--;
            }
        }
        for(int row=0;row<n;row++){  //o(n^2)
            for(int col=1;col<n;col++){
                arr[row][col]+=arr[row][col-1];
            }
        }

        return arr;
        
    }
};