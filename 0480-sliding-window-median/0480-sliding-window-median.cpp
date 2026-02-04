class Solution {
public:
    void add(multiset<int>&firstHalf,multiset<int>&secondHalf,int val){
        secondHalf.insert(val);
        if(firstHalf.size()<secondHalf.size()){
            //  cout<<"m";
            int val=*secondHalf.begin();
            // cout<<val;
            secondHalf.erase(secondHalf.begin());
            firstHalf.insert(val);
            // cout<<firstHalf.size()<<" "<<secondHalf.size()<<endl;

        }
        else if(*firstHalf.rbegin()>*secondHalf.begin()){
            int val1 = *firstHalf.rbegin();
            firstHalf.erase(firstHalf.find(val1));
            int val2 =  *secondHalf.begin();
          
            secondHalf.erase(secondHalf.begin());
            firstHalf.insert(val2);
            secondHalf.insert(val1);

        }
    }

   void remove(multiset<int>&firstHalf,multiset<int>&secondHalf,int val){

        if(secondHalf.find(val)!=secondHalf.end()){
           
            secondHalf.erase(secondHalf.find(val));
            if((firstHalf.size()-secondHalf.size())>1){
                 int value=*firstHalf.rbegin();
        firstHalf.erase(firstHalf.find(value));
        secondHalf.insert(value);


            }
            return;
        }
        // cout<<"m"<<val<<endl;
        firstHalf.erase(firstHalf.find(val));
        int value=*secondHalf.begin();
        if(firstHalf.size()<secondHalf.size()){
        secondHalf.erase(secondHalf.begin());
        firstHalf.insert(value);
        }


    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        multiset<int>firstHalf;
        multiset<int>secondHalf;
        int n=nums.size();

        vector<double>ans;

        for(int i=0;i<n;i++){
           add(firstHalf,secondHalf,nums[i]);
           if(i>=k){
            remove(firstHalf,secondHalf,nums[i-k]);
           }
           if(i>=(k-1)){
            cout<<firstHalf.size()<<endl;
            double val;
            if(k%2==1) val =(1.0*(*firstHalf.rbegin()));
            else{
                val = (1.0*(*firstHalf.rbegin()+(long double)*secondHalf.begin()))/2;
            }
            ans.push_back(val);
           }

        }

        return ans;
        
    }
};