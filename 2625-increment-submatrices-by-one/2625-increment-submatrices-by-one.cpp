class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>arr(n,vector<int>(n,0));
        for(auto it: queries){  //o(q*n)
            int row1=it[0];  
            int col1=it[1];
            int row2=it[2];
            int col2=it[3];
           arr[row1][col1]++;
           if((col2+1)<n) arr[row1][col2+1]--;
           if((row2+1)<n) arr[row2+1][col1]--;
           if((col2+1)<n&&(row2+1)<n) arr[row2+1][col2+1]++;
        }
        for(int row=0;row<n;row++){  //o(n^2)
            for(int col=0;col<n;col++){
               int above = row ? arr[row-1][col] : 0;
               int left= col ? arr[row][col-1] : 0;
               int diagonal = (row&&col) ? arr[row-1][col-1] : 0;
               arr[row][col]+=(left+above-diagonal);
                
            }
        }

        return arr;
        
    }
};