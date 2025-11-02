class Solution {
public:
const int UNGAURDED = 0;
const int GUARDED=1;
const int GUARD= 2;
const int WALL=3;

void markGuarded(int row,int col,vector<vector<int>>&grid,int m,int n){

    //Traverse upwards
    for(int r=row-1;r>=0;r--){
        if(grid[r][col]==WALL||grid[r][col]==GUARD) break;
        grid[r][col]=GUARDED;
    }

     //Traverse downwards
    for(int r=row+1;r<m;r++){
        if(grid[r][col]==WALL||grid[r][col]==GUARD) break;
        grid[r][col]=GUARDED;
    }

     //Traverse left
    for(int c=col-1;c>=0;c--){
        if(grid[row][c]==WALL||grid[row][c]==GUARD) break;
        grid[row][c]=GUARDED;
    }

     //Traverse rightward
    for(int c=col+1;c<n;c++){
         if(grid[row][c]==WALL||grid[row][c]==GUARD) break;
        grid[row][c]=GUARDED;
    }

    

    
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
        for(auto guard:guards){
            markGuarded(guard[0],guard[1],grid,m,n);
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