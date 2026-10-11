class DetectSquares {
public:
    static const int N=1e3+1;
    int pointsCoordinate[N][N]={0,0};
    vector<vector<int>>points;
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        points.push_back(point);
        pointsCoordinate[point[0]][point[1]]++;
        
    }
    
    int count(vector<int> point) {
        int x1=point[0];
        int y1=point[1];
        int tot=0;
        for(auto &p:points){
            int x2=p[0];
            int y2=p[1];
            if(abs((x1-x2))>0&&abs((x1-x2))==abs((y1-y2))) tot+=pointsCoordinate[x1][y2]*pointsCoordinate[x2][y1]; 
        }
        return tot;
        
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */