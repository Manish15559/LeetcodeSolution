class Solution {
public:
    int findTheWinner(int n, int k) {
        deque<int>pq;
        for(int i=1;i<=n;i++) pq.push_back(i);

        int cnt=0;
        while(pq.size()>1){
            cnt++;
            int val=pq.front();
            pq.pop_front();
            if(cnt==k){
                cnt=0;
            }
            else{
                pq.push_back(val);
            }
        }

        return pq.front();

        
    }
};