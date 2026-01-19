class Solution {
public:
int pref[301][301];
bool check(int side,int threshold,int n,int m){

    for(int i=side;i<=n;i++){
        for(int j=side;j<=m;j++){
            int val=pref[i][j]-pref[i][j-side]-pref[i-side][j]+pref[i-side][j-side];
            if(threshold>=val) return true;
        }
    }
    return false;
}
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n=mat.size();
        int m=mat[0].size();
       memset(pref,0,sizeof(pref));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
               

                pref[i][j]=pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+mat[i-1][j-1];


            }
        }

        int low=0;
        int high=min(n,m);
        while(high-low>1){
            int mid=(low+high)/2;
            if(check(mid,threshold,n,m)) low=mid;
            else high=mid-1;
        }
        if(check(high,threshold,n,m)) return high;
        else return low;
       
        // return ans;
        
    }
};