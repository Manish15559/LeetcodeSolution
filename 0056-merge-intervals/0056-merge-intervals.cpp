class Solution {
public:
    static bool comp(vector<int>a,vector<int>b){
        return a[1]>b[1];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(),intervals.end(),comp);

        vector<vector<int>>merge;
        merge.push_back(intervals[0]);

        for(int i=1;i<intervals.size();i++){
            if(merge.back()[0]<=intervals[i][1])  merge.back()[0]=min(intervals[i][0],merge.back()[0]);
            else  merge.push_back(intervals[i]);
        }

        return merge;
        
    }
};