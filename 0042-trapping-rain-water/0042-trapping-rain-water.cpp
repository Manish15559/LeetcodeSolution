class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>leftMax(n,-1);  //leftmax[i] -> max height on the left of i
        vector<int>rightMax(n,-1);
        int currMax=-1;

        for(int i=0;i<n;i++){
           leftMax[i]=currMax;
           currMax=max(currMax,height[i]);
            
        }
        currMax=-1;
        for(int i=n-1;i>=0;i--){
            rightMax[i]=currMax;
            currMax=max(height[i],currMax);

        }
        int waterStore=0;
        for(int i=0;i<n;i++){
            int mx=min(leftMax[i],rightMax[i]);
            if(mx>height[i]) waterStore+=(mx-height[i]);
        }

        return waterStore;
 
        
    }
};