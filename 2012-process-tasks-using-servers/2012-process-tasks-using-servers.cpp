class Solution {
public:
class AvailableType{
    public:
    int weight;
    int idx;

    AvailableType(int w,int i){
        weight=w;
        idx=i;
    }
};
class UsedType{
    public:
    long long freeTime;
    int idx;
    UsedType(long long e,int i){
        freeTime=e;
        idx=i;
    }
};

class cmp1{
    public:
    bool operator()(AvailableType &a,AvailableType &b){
        if(a.weight!=b.weight) return a.weight>b.weight;
        else return a.idx>b.idx;
    }
};

class cmp2{
    public:
    bool operator()(UsedType &a,UsedType &b){
        if(a.freeTime!=b.freeTime) return a.freeTime>b.freeTime;
        else return a.idx>b.idx;
    }
};

    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
    priority_queue<AvailableType,vector<AvailableType>,cmp1>availables;
    priority_queue<UsedType,vector<UsedType>,cmp2>useds;

    int n=servers.size();

    for(int i=0;i<n;i++){
        availables.push(AvailableType(servers[i],i));
    }

    int m=tasks.size();
    long long currTime=0;
    vector<int>ans(m,0);

    for(int task=0;task<m;task++){
        currTime=max(currTime,(long long)(1+task));

        while(!useds.empty()&&useds.top().freeTime<=currTime){
            UsedType server = useds.top();
            useds.pop();
            availables.push(AvailableType(servers[server.idx],server.idx));
        }

        if(availables.empty()){
            currTime= useds.top().freeTime;
            while(!useds.empty()&&useds.top().freeTime<=currTime){
            UsedType server = useds.top();
            useds.pop();
            availables.push(AvailableType(servers[server.idx],server.idx));
        }

        }
        AvailableType server = availables.top();
        availables.pop();
        useds.push(UsedType((currTime+tasks[task]),server.idx));
        ans[task]=server.idx;
    }

    return ans;
    


        
    }
};