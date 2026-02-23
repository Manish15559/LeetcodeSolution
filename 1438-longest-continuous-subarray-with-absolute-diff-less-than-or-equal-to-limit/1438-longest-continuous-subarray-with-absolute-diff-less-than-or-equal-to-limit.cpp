class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int left=0;
        deque<int>maxi,mini;
        int ans=1;
        for(int right=0;right<nums.size();right++){
           while(!maxi.empty()&&maxi.back()<nums[right]) maxi.pop_back();
           while(!mini.empty()&&mini.back()>nums[right]) mini.pop_back();
           maxi.push_back(nums[right]);
           mini.push_back(nums[right]);

           while((maxi.front()-mini.front())>limit){
            if(maxi.front()==nums[left]) maxi.pop_front();
            if(mini.front()==nums[left]) mini.pop_front();
            left++;
           }
           ans=max(ans,(right-left+1));


          

        }
        return ans;
        
    }
};