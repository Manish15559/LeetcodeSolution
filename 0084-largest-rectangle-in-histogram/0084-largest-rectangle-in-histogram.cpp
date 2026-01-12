class Solution {
public:
    vector<int> findNse(vector<int>& heights, int n){
        vector<int>nse(n,-1);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&heights[st.top()]>=heights[i]) st.pop();
            if(st.empty()) nse[i]=n;
            else nse[i]=st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> findPse(vector<int>& heights, int n){
        vector<int>pse(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&heights[st.top()]>=heights[i]) st.pop();
            if(st.empty()) pse[i]=-1;
            else pse[i]=st.top();
            st.push(i);
        }
        return pse;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>nse=findNse(heights,n);
        vector<int>pse=findPse(heights,n);
        int ans=0;
        for(int i=0;i<n;i++){
            int width= nse[i]-pse[i]-1;
            ans=max(ans,(width*heights[i]));
        }

        return ans;
        
    }
};