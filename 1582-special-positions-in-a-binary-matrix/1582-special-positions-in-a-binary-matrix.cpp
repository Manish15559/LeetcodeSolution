class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
           int rowOnes=0;
           int colidx=-1;
           for(int j=0;j<m;j++){
            if(mat[i][j]==1){
                rowOnes++;
                colidx=j;
            }

           }
           if(rowOnes==1){
            int colOnes=0;
            for(int k=0;k<n;k++){
                if(mat[k][colidx]==1) colOnes++;
            }
            if(colOnes==1) ans++;
           }
           
        }

      
        return ans;
        
    }
};