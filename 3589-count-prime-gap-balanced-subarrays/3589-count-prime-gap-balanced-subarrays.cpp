class Solution {
public:
    int primeSubarray(vector<int>& nums, int k) {

        int range = *max_element(nums.begin(),nums.end());
        int n=nums.size();

        vector<bool>isPrime(range+1,true);
        isPrime[0]=isPrime[1]=false;
        for(int i=2;i<=range;i++){
            if(isPrime[i]){
                for(int j=2*i;j<=range;j+=i) isPrime[j]=false;
            }
        }

        int l=0;
        int prev=-1;
        int curr=-1;
        multiset<int>st;
        int ans=0;

        for(int r=0;r<n;r++){
            if(isPrime[nums[r]]){
                 prev=curr;
                curr=r;
               st.insert(nums[r]);
            }

            while(st.size()&&(*st.rbegin()-*st.begin())>k){
                if(isPrime[nums[l]]) st.erase(st.find(nums[l]));

                l++;
            }

            if(st.size()>=2){
                ans+=(prev-l+1);
            }
        }

        return ans;



        
        
    }
};