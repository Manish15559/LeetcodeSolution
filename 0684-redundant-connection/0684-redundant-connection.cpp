class DisJoint{
    vector<int>size;
    vector<int>parent;

    public:
    DisJoint(int n){
        size.resize(n+1,1);
        parent.resize(n+1,0);
        for(int i=0;i<=n;i++) parent[i]=i; 
    }

    int findParent(int node){
        if(node==parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }

    bool unionBySize(int u,int v){
        int parentU = findParent(u);
        int parentV = findParent(v);
        if(parentU==parentV) return false;

        if(size[parentU]>size[parentV]){
            parent[parentV]=parentU;
            size[parentU]+=size[parentV];
        }
        else{
             parent[parentU]=parentV;
            size[parentV]+=size[parentU];
        }

        return true;
    }

};


class Solution {
public:

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n=edges.size();

        DisJoint *obj =new DisJoint(n);

        for(auto it:edges){
            if(obj->unionBySize(it[0],it[1])==false) return it;
        }

        return {};
        
    }
};