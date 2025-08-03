class Solution {
public:
    int minTime(string s, vector<int>& order, int k) {
        set<int>st;
        long long n=order.size();
        st.insert(-1);
        st.insert(n);
        long long notValid=(n*(n+1))/2;
        for(int i=0;i<n;i++){
            auto idx= st.upper_bound(order[i]);
            int right = *(idx);
            int left= *(--idx);

            long long len=(right-left-1);

            notValid-=((len*(len+1))/2);

            long long len1=(order[i]-left-1);
            long long len2=(right-order[i]-1);

            notValid+=(len1*(len1+1))/2;
            notValid+=(len2*(len2+1))/2;

            long long curr =((n*(n+1))/2)-notValid;
            // cout<<len1<<" "<<len2<<endl;
            // cout<<curr<<" "<<notValid<<endl;

            if(curr>=k) return i;

            st.insert(order[i]);


        }

        return -1;

        
    }
};