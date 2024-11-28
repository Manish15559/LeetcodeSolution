class Solution {
public:


    int maxEvents(vector<vector<int>>& events) {
       sort(events.begin(),events.end());
        int cnt=0;
      priority_queue<int,vector<int>,greater<int>>pq;
        int idx=0;
        int n=events.size();
       for(int day=1;day<=1e5;day++){
        while(idx<n&&events[idx][0]==day){
            pq.push(events[idx][1]);
            idx++;
        }
        while(!pq.empty()&&pq.top()<day) pq.pop();
        if(!pq.empty()){
            pq.pop();
            cnt++;
        }


       }
       return cnt;
        
    }
};