#include<bits/stdc++.h>
using namespace std;

class DetectSquares {
public:
   static const int N=1001;
   int cnt[N][N]={0};
   vector<pair<int,int>> points;
   
    DetectSquares() {
    
    }
    
    void add(vector<int> point) {
       points.push_back({point[0],point[1]});
       cnt[point[0]][point[1]]++;
        
    }
   
    
    int count(vector<int> point) {
        int ans=0;
        int x=point[0];
        int y=point[1];

        for(auto&[x1,y1] : points){
            if(abs(x-x1)>0&&abs(x-x1)==abs(y-y1)){
                ans+= cnt[x][y1]*cnt[x1][y];
            }
        }

       return ans;


        
        
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */