class SegmentTree{

    vector<int>seg;
    public:
    SegmentTree(int n){
        seg.resize(4*n,0);
    }
  
    void update(int idx,int low,int high,int ind,int val){
        if(low==high){
            seg[idx]=max(val,seg[idx]);
            return;
        }
        int mid=(low+high)/2;
        if(ind<=mid) update(2*idx+1,low,mid,ind,val);
        else update(2*idx+2,mid+1,high,ind,val);
        seg[idx]=max(seg[2*idx+1],seg[2*idx+2]);
    }
    int query(int idx,int low,int high,int l,int r){

        if(r<low||high<l) return -1;
        if(l<=low&&high<=r) return seg[idx];
        int mid=(low+high)/2;
        int left=query(2*idx+1,low,mid,l,r);
        int right=query(2*idx+2,mid+1,high,l,r);

        return max(left,right);
    }
};


class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        sort(envelopes.begin(),envelopes.end(),comp);
        int mx=0;
        for(auto it:envelopes) mx=max(it[1],mx);
        SegmentTree *obj=new SegmentTree(mx+1);
        int  ans=0;
        for(auto envelope:envelopes){
            int val=obj->query(0,0,mx,0,(envelope[1]-1));
             ans=max(ans,(val+1));
             obj->update(0,0,mx,envelope[1],(val+1));
        }
        return ans;

        
    }
};