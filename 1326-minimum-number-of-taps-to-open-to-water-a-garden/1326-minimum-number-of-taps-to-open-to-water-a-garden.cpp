class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {

        vector<pair<int,int>>arr;
        for(int i=0;i<=n;i++){
            if(ranges[i]==0) continue;
            int left=max(0,(i-ranges[i]));
            int right=min(n,(i+ranges[i]));
            arr.push_back({left,right});
        }

        sort(arr.begin(),arr.end());

        stack<pair<int,int>>st;
        // st.push(arr[0]);
        for(auto it:arr){
            int left=it.first;
            int right=it.second;
            if(st.empty()) st.push(it);
            else if(st.top().second<right&&left<=st.top().second){
                while(!st.empty()&&st.top().first>=left) st.pop();
                if(st.empty()) st.push({it});
                else st.push({st.top().second,it.second});

            }
        }
        if(st.empty()) return -1;
        if(st.top().second==n){
            int k=n+1;
            int count=0;
            while(!st.empty()) {
                count++;
                k=min(k,st.top().first);
                st.pop();
            }
            if(k==0) return count;
        }
         return -1;
        
    }
};