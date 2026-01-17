class Solution {
public:
  long long findSquare(vector<int>&bottomLeft1,vector<int>&topRight1,vector<int>&bottomLeft2,vector<int>&topRight2){
    int l1=bottomLeft1[0];
    int r1=topRight1[0];
    int b1=bottomLeft1[1];
    int t1=topRight1[1];
    int l2=bottomLeft2[0];
    int r2=topRight2[0];
    int b2=bottomLeft2[1];
    int t2=topRight2[1];
    if(max(l1,l2)<min(r1,r2)&&max(b1,b2)<min(t1,t2)){
        int l=max(l1,l2);
        int r=min(r1,r2);
        int b=max(b1,b2);
        int t=min(t1,t2);
        int side=min((r-l),(t-b));
        return (side*1ll*side);
    }
    return 0;


  }
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n=bottomLeft.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans=max(ans,findSquare(bottomLeft[i],topRight[i],bottomLeft[j],topRight[j]));
            }
        }

        return ans;
        
    }
};