class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int smallest=1e9;
        int n=matrix.size();
        int m=matrix[0].size();
        long long sum=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum+=abs(matrix[i][j]);
                smallest=min(abs(matrix[i][j]),smallest);
                cnt+=(matrix[i][j]<0);
            }
        }
       
        if(cnt&1) sum-=(2*smallest);

        return sum;

        
    }
};