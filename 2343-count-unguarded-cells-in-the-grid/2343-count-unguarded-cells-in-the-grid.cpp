class Solution {
public:
const int UNGAURDED = 0;
const int GUARDED=1;
const int GUARD= 2;
const int WALL=3;

bool isGaurded(int row,int col,vector<vector<int>>&grid,bool isPreviousGuard){
    if(grid[row][col]==GUARD) return true;
    else if(grid[row][col]==WALL) return false;
    else if(isPreviousGuard) grid[row][col]=GUARDED;

    return isPreviousGuard;
}
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {

        vector<vector<int>>grid(m,vector<int>(n,UNGAURDED));

        for(auto it:walls){
            int row=it[0];
            int col=it[1];
            grid[row][col]=WALL;

        }
        for(auto it:guards){
            int row=it[0];
            int col=it[1];
            grid[row][col]=GUARD;
        }

        for(int row=0;row<m;row++){
            bool isPreviousGuard = grid[row][0]==GUARD;
            for(int col=1;col<n;col++) isPreviousGuard=isGaurded(row,col,grid,isPreviousGuard);

            isPreviousGuard = grid[row][n-1]==GUARD;

             for(int col=n-2;col>=0;col--) isPreviousGuard=isGaurded(row,col,grid,isPreviousGuard);


        }

         for(int col=0;col<n;col++){
            bool isPreviousGuard = grid[0][col]==GUARD;
            for(int row=1;row<m;row++) isPreviousGuard=isGaurded(row,col,grid,isPreviousGuard);

            isPreviousGuard = grid[m-1][col]==GUARD;

             for(int row=m-2;row>=0;row--) isPreviousGuard=isGaurded(row,col,grid,isPreviousGuard);


        }
        
        

        int ans=0;
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                ans+=(grid[row][col]==UNGAURDED);
            }
        }

        return ans;
 
        
    }
};