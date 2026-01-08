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

    void UnionByRank(int u,int v){
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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {

        int n=s.size();
        DisJoint *obj = new DisJoint(n);
        for(auto it:pairs){
            obj->UnionByRank(it[0],it[1]);
        }
        unordered_map<int,string>mp;
        for(int i=0;i<n;i++){
            int parent=obj->findParent(i);
            mp[parent].push_back(s[i]);
        }

        for(auto &it:mp){
            sort(it.second.begin(),it.second.end());
            reverse(it.second.begin(),it.second.end());
        }
        string ans;

        for(int i=0;i<n;i++){
            int parent=obj->findParent(i);
            char ch=mp[parent].back();
            mp[parent].pop_back();
            ans.push_back(ch);
        }

        return ans;

        
    }
};