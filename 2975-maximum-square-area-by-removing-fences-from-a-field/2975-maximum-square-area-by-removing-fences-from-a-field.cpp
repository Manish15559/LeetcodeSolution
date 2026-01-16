class Solution {
public:
    int cal(long long val,int mod) {
        return ((val%mod)*(val%mod))%mod;
    }
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        int mod=1e9+7;
       

        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());

        int ans=-1;
        unordered_set<int>st;
        st.insert(m-1);
        for(int i=0;i<hFences.size();i++){
            st.insert((hFences[i]-1));
            st.insert((m-hFences[i]));
            for(int j=i-1;j>=0;j--){
                st.insert((hFences[i]-hFences[j]));
            }
        }
        for(int i=0;i<vFences.size();i++){
            int left=vFences[i]-1;
            int right=n-vFences[i];
            if(st.find(left)!=st.end()) ans=max(ans,left); 
            if(st.find(right)!=st.end()) ans=max(ans,right);
             for(int j=i-1;j>=0;j--){
               int val =((vFences[i]-vFences[j]));
               if(st.find(val)!=st.end()) ans=max(ans,val);
            } 
        }
        if(st.find(n-1)!=st.end()) ans=max(ans,(n-1));
        if(ans==-1) return -1;

        return cal(ans,mod);


        
    }
};