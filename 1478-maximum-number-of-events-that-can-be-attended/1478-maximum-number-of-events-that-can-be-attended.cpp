class Solution {
public:
static bool comp(vector<int>a,vector<int>b){
    if(a[0]!=b[0]) return a[0]<b[0];
    return a[1]<b[1];
}
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();

        sort(events.begin(),events.end(),comp);
        int ans=0;
        priority_queue<int,vector<int>,greater<int>>q;
        int idx=0;
        for(int day=1;day<=1e5;day++){
            while(idx<n&&events[idx][0]<=day){
                q.push(events[idx][1]);
                idx++;
            }
            while(!q.empty()&&q.top()<day) q.pop();

            if(!q.empty()){
                ans++;
                q.pop();
            }

            
        }
        return ans;
        
    }
};