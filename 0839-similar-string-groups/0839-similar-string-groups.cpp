class DisJoint{
    vector<int>parent;
    vector<int>rank;
    public:
    DisJoint(int n){
        parent.resize(n);
        rank.resize(n,1);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    int findParent(int node){   //tc = o(4*alpha) =constant 
        if(parent[node]==node) return node;
        return parent[node]=findParent(parent[node]);
    }

    void unionByRank(int u,int v){
        int ultiParentU =findParent(u);
        int ultiParentV = findParent(v);
        if(ultiParentU==ultiParentV) return;

        if(rank[ultiParentU]>rank[ultiParentV]){
            parent[ultiParentV]=ultiParentU;
        }
        else if(rank[ultiParentV]>rank[ultiParentU]){
            parent[ultiParentU]=ultiParentV;
        }
        else{
            rank[ultiParentV]++;
            parent[ultiParentU]=ultiParentV;

        }
     }

     bool isConnected(int u,int v) {
        return findParent(u)==findParent(v);
     }

     int countGroup(int n){
        int cnt=0;
        for(int i=0;i<n;i++) cnt+=(parent[i]==i);
        return cnt;
     }
};


class Solution {
public:
    bool sameGroup(string &str1,string &str2){
        int cnt=0;
        int sz=str1.size();
        for(int i=0;i<sz;i++) cnt+=(str1[i]!=str2[i]);
        return cnt<=2;
    }
    int numSimilarGroups(vector<string>& strs) {

        int n=strs.size();

        DisJoint *obj= new DisJoint(n);
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(obj->isConnected(i,j)||sameGroup(strs[i],strs[j])==false) continue;
                obj->unionByRank(i,j);

            }
        }
        int ans=obj->countGroup(n);

        return ans;
        
        
    }
};