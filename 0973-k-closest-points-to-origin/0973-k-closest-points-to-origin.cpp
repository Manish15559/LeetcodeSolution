class Solution {
public:
    int distance(vector<int>&point){

        return ((point[0]*point[0])+(point[1]*point[1]));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int,int>>pq; //maxHeap
        int n=points.size();
        for(int i=0;i<n;i++){
            pq.push({distance(points[i]),i});
            if(i>=k) pq.pop();
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            ans.push_back(points[it.second]);
        }

        return ans;

        
    }
};