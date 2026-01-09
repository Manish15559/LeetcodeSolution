class DisJoint{
    vector<int>size,parent;
    public:
    DisJoint(int n){
        size.resize(n,1);
        parent.resize(n+1);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int findParent(int node){
        if(node==parent[node]) return node;
        return parent[node]=findParent(parent[node]);
    }
    void unionByRank(int u,int v){
        int parentU=findParent(u);
        int parentV=findParent(v);
        if(parentU==parentV) return;
        if(size[parentU]>size[parentV]){
            parent[parentV]=parentU;
            size[parentU]+=size[parentV];
        }
        else{
            parent[parentU]=parentV;
            size[parentV]+=size[parentU];

        }
    }
};
class Solution {
public:

    bool equationsPossible(vector<string>& equations) {
        DisJoint *obj=new DisJoint(128);
        for(auto it:equations){
            if(it[1]=='=') obj->unionByRank(it[0],it[3]);
        }
        for(auto it:equations){
            if(it[1]=='!'){
                if(obj->findParent(it[0])==obj->findParent(it[3])) return false;
            }
        }
        return true;

        
    }
};