class Solution {
public:
    vector<long long> countStableSubarrays(vector<int>& nums, vector<vector<int>>& queries) {

        vector<int>arr;
        stack<int>st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(!st.empty()&&nums[st.top()]<=nums[i]) st.pop();
            if(st.empty()) arr.push_back(-1);
            else arr.push_back((st.top()));
            st.push(i);
        }
        vector<long long>pref1,pref2;
        pref1.push_back(0);
        pref2.push_back(0);
        for(int i=1;i<=n;i++){
            long long val= pref1[i-1]+(arr[i-1]);
            pref1.push_back(val);
            long long val2=pref2[i-1]+i-1;
            pref2.push_back(val2);
        }
        
        vector<long long>ans;
        for(auto it:queries){
            int l=it[0];
            int r=it[1];
            int idx=upper_bound(arr.begin(),arr.end(),(l-1))-arr.begin();
            idx--;
            cout<<idx<<endl;
            // int idx1=max(idx1,idx);
             idx=min(idx,r);
            int cnt1=idx-l+1;
            int cnt2=r-idx;
            long long ans1=(cnt1*(l-1));
            ans1=(pref2[idx+1]-pref2[l]-ans1);
           
            long long ans2=(pref2[r+1]-pref2[idx+1])-(pref1[r+1]-pref1[idx+1]);
            ans.push_back((ans1+ans2));
        }
        return ans;
        
    }
};