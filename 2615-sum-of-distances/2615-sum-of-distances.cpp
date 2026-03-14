class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,long long>count,sum;
        vector<long long>ans(n,0);
        for(int i=0;i<n;i++){
            if(count[nums[i]]>0){
               
                ans[i]=(count[nums[i]]*i)-sum[nums[i]];
            }
            count[nums[i]]++;
            sum[nums[i]]+=i;
        }
        count.clear();
        sum.clear();
        for(int i=n-1;i>=0;i--){
            if(count[nums[i]]>0){
               
                ans[i]+=sum[nums[i]]-(count[nums[i]]*i);
            }
            count[nums[i]]++;
            sum[nums[i]]+=i;
        }
        return ans;
        
    }
};