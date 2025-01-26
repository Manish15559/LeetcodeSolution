class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
  int ans=0;
  int mxl=0;
  int mxr=0;
  int l=0;
  int r=n-1;
  
  while (l <= r) {
    if (height[l] <= height[r]) {
      if (height[l] >= mxl) {
        mxl = height[l];
      } else {
        ans += mxl - height[l];
      }
      l++;
    } else {
      if (height[r] >= mxr) {
        mxr = height[r];
      } else {
        ans += mxr - height[r];
      }
      r--;
    }
  }
  return ans;
        
    }
};