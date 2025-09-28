#include<bits/stdc++.h>
using namespace std;

class DetectSquares {
public:
   
    map<pair<int,int>,int>cnt;
   
    DetectSquares() {
    
    }
    
    void add(vector<int> point) {
        int x_coordinate=point[0];
        int y_coordinate=point[1];
        cnt[{x_coordinate,y_coordinate}]++;
        
    }
    int cal(int x,int y,int dx,int dy){
        int c=0;
        int old_x=x;
        int old_y=y;
        while(x>=0&&x<=1000&&y>=0&&y<=1000){
            x+=dx;
            y+=dy;
            if(cnt.find({x,old_y})!=cnt.end()&&cnt.find({old_x,y})!=cnt.end()&&cnt.find({x,y})!=cnt.end()) c+=(cnt[{old_x,y}]*cnt[{x,old_y}]*cnt[{x,y}]);
        }
        return c;
    }
    
    int count(vector<int> point) {
        int c=0;

        //first quadrant
        int x=point[0];
        int y=point[1];
        int dx[]={-1,1,1,-1};
        int dy[]={1,1,-1,-1};
        for(int i=0;i<4;i++) c+=cal(x,y,dx[i],dy[i]);

        return c;


        
        
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */