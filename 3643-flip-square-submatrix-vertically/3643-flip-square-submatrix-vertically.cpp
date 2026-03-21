class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        // vector<vector<int>>ans(k,vector<int>(ans,0));

       for(int col=y;col<y+k;col++){
        int top=x;
        int down=x+k-1;
        while(down>top){
            // cout<<grid[top][col]<<" "<<grid[down][col]<<endl;
            swap(grid[top][col],grid[down][col]);
            // cout<<grid[top][col]<<" "<<grid[down][col]<<endl;
            down--;
            top++;
        }
       }
       return grid;
        
    }
};