class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        vector<int>value;
        int n=grid.size();
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==0) count++;
                else break;

            }
            value.push_back(count);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int required = (n-1-i);
            int j=i;
            while(j<n&&value[j]<required) j++;
            if(j==n) return -1;
            while(j>i){
                swap(value[j],value[j-1]);
                ans++;
                j--;
            }
        }
        return ans;
        
    }
};