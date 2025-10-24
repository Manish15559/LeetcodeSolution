class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        int n=nums.size();
        
        for(auto it:nums){  
            freq[it]++;
        }
        vector<vector<int>> arr(n+1);
        for(auto it:freq){  
           arr[it.second].push_back(it.first);
        }
        vector<int>ans;
        for(int i=n;i>=0&&ans.size()<k;i--){
            for(int num:arr[i]){
                ans.push_back(num);
                if(ans.size()==k) break;
            }
        }
      
        return ans;
        
    }
};