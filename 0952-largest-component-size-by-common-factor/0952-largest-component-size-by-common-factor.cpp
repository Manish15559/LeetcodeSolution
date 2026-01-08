class DisJoint{
    vector<int>size,parent;

    public:
    DisJoint(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    int findParent(int n){
        if(n==parent[n]) return n;
        return parent[n]=findParent(parent[n]);
    }

    void unionByRank(int u,int v){
        int x=findParent(u);
        int y=findParent(v);
        if(x==y) return;
        if(size[x]>size[y]){
            size[x]+=size[y];
            parent[y]=x;
        }
        else{
            size[y]+=size[x];
            parent[x]=y;
        }
    }

};
class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
    int mx =*max_element(nums.begin(),nums.end());
    DisJoint *obj= new DisJoint(mx+1);
    for(auto it:nums){
        for(int i=2;i*i<=it;i++){
            if((it%i)==0) {
                // cout<<i<<" "<<it<<endl;
                obj->unionByRank(it,i);
                obj->unionByRank(it,it/i);
            }
        }
    }

    unordered_map<int,int>cnt;
    int ans=0;
    for(auto it:nums){
        int parent= obj->findParent(it);
        // cout<<parent<<endl;
        
        cnt[parent]++;
        ans=max(ans,cnt[parent]);
    }

    return ans;
        
    }
};