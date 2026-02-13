class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if(x==y) return 0;
        if(x<y) return (y-x);
        queue<pair<int,int>>q;
        vector<int>vis((2*x-y+1),0);
        q.push({x,0});
        vis[x]=1;


        while(!q.empty()){
            int node=q.front().first;
            int times=q.front().second;
            q.pop();
            // if(vis[node]==1) continue;
            //divide by 11
            if(node%11==0&&vis[node%11]==0){
                if(node/11==y) return times+1;
                q.push({(node/11),(times+1)});
                vis[node/11]=1;
            }
            if(node%5==0&&vis[node%5]==0){
                if(node/5==y) return times+1;
                q.push({(node/5),(times+1)});
                vis[node/5]=1;
            }
            if(node<(2*x-y)&&vis[(node+1)]==0){
                if((node+1)==y) return times+1;
                q.push({(node+1),(times+1)});
                vis[(node+1)]=1;
            }
            if((node-1)>=0&&vis[(node-1)]==0){
                if((node-1)==y) return times+1;
                q.push({(node-1),(times+1)});
                vis[(node-1)]=1;
            }
        }

        return -1;
        
    }
};