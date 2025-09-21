class Solution {
public:

vector<vector<int>> helper(vector<int>&a){  //geenrate next set of permutations
int n=a.size();
vector<vector<int>>result;
for(int l=0;l<n;l++){
    for(int r=l;r<n;r++){
        vector<int>cutpiece(a.begin()+l,a.begin()+r+1);
        vector<int> remaining;
        for(int i=0;i<n;i++){
            if(i<l||i>r){
                remaining.push_back(a[i]);
            }
        }

        for(int i=0;i<=remaining.size();i++){
            vector<int>final;
            final.insert(final.end(),remaining.begin(),remaining.begin()+i);
            final.insert(final.end(),cutpiece.begin(),cutpiece.end());
            final.insert(final.end(),remaining.begin()+i,remaining.end());
            if(final!=a) result.push_back(final);
        }
    }

}

return result;

}


    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {

        queue<pair<vector<int>,int>>q;
        q.push({nums1,0});

        map<vector<int>,int>vis;
        vis[nums1]++;

        while(!q.empty()){

            auto it=q.front(); 
            q.pop();

            
            if(it.first==nums2) return it.second;
            vector<vector<int>> result=helper(it.first);
            for(auto iter:result){
                if(!vis[iter]){
                    q.push({iter,(it.second+1)});
                    vis[iter]++;
                }
            }
        }
        return 0;


        
    }
};