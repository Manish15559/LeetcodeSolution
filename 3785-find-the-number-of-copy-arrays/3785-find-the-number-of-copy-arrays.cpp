class Solution {
public:

bool isOverlapping(int x1,int y1,int x2,int y2){
    return max(x1,x2)<=min(y1,y2);
}
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {

        int n=original.size();
        int left=bounds[0][0];
        int right=bounds[0][1];

        

      
        for(int i=1;i<n;i++){
            int diff=original[i]-original[i-1];
            left+=diff;
            right+=diff;

            if(!isOverlapping(left,right,bounds[i][0],bounds[i][1])) return 0;

            left=max(left,bounds[i][0]);
            right=min(right,bounds[i][1]);
           


        }
        return (right-left+1);
        
    }
};