class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());

        int width=1;
        int curr=1;
        for(int i=1;i<vBars.size();i++){
            if(vBars[i]==(vBars[i-1]+1)) curr++;
            else curr=1;
            width=max(curr,width);
        }
        int height=1;
        curr=1;
        for(int i=1;i<hBars.size();i++){
            if(hBars[i]==(hBars[i-1]+1)) curr++;
            else curr=1;
            height=max(curr,height);
        }

        int side=min(height,width)+1;
        return (side*side);

        
    }
};