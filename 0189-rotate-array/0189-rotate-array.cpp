class Solution {
public:
    void reverseList(vector<int>&arr,int left,int right){
        while(left<right){
            swap(arr[left],arr[right]);
            left++;
            right--;
        }
    }
    void rotate(vector<int>& nums, int k) {

        // 1 2 3 4 5 6 7  => k=3 => 5 6 7 1 2 3 4

        // store the last k element in a temp varibale = > 5 6 7
        // then from last element of the first (n-k) element i will swap them to there new position
        // 5 6 7 => temp
        // 1 2 3 4 5 6 7 =>

        // vector<int>temp;
        // int n=nums.size();
        // k%=n;
        // for(int i=n-k;i<n;i++){
        //     temp.push_back(nums[i]);

        // }

        // for(int i=n-k-1;i>=0;i--){
        //     swap(nums[i],nums[i+k]);
        // }

        // for(int i=0;i<k;i++){
        //     nums[i]=temp[i];
        // }

        // 1 2 3 4 5 => k=2 => 4 5 1 2 3
        // first (n-k) element + last k elemnt  => last k element + first (n-k) element
        //                                             5 4 3 2 1
        //                                             4 5 3 2 1
        //                                             4 5 1 2 3

        int n=nums.size();
        k%=n;
        reverseList(nums,0,n-1);
        reverseList(nums,0,k-1);
        reverseList(nums,k,n-1);
      
    }
};