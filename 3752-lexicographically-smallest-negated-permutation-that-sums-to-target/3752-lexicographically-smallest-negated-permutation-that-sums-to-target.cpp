class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {

      vector<int>neg(n+1,0);
      long long curr=((long long)n*(n+1))/2;
      int idx=n;
      while(curr>target&&idx>0){
        int val=2*idx;
        if((curr-val)>=target){
            neg[idx]=1;
            curr-=(val);
        }
        idx--;


      }
      if(target!=curr) return {};
      vector<int>ans;
      for(int i=n;i>=1;i--) if(neg[i]) ans.push_back((-1*i));
      for(int i=1;i<=n;i++) if(!neg[i]) ans.push_back(i);

      return ans;
        
    }
};