class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {

        vector<vector<int>>arr;//{nums1,nums2,idx}

        int n=nums1.size();
        for(int i=0;i<n;i++){
            arr.push_back({nums1[i],nums2[i],i});
        }
        sort(arr.begin(),arr.end());
        vector<long long>ans(n);
        int left=0;
        long long curr_sum=0;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int right=0;right<n;right++){
            while(arr[left][0]<arr[right][0]){
                curr_sum+=arr[left][1];
                pq.push(arr[left][1]);
                left++;
            }
            while((pq.size())>k){
                curr_sum-=pq.top();
                pq.pop();
                
            }
            ans[arr[right][2]]=curr_sum;
            
        }

        return ans;
        
    }
};