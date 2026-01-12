class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left=0;
        int right=n-1;
        int leftMax=-1;
        int rightMax=-1;
        int waterTrap=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=leftMax) leftMax=height[left];
                else waterTrap+=(leftMax-height[left]);
                left++;
            }
            else{
                if(height[right]>=rightMax) rightMax=height[right];
                else waterTrap+=(rightMax-height[right]);
                right--;
            }
        }

        return waterTrap;
 
        
    }
};