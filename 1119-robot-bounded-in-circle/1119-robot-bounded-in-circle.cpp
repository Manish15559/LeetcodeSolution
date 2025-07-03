class Solution {
public:
    bool isRobotBounded(string instructions) {

    set<pair<int,int>>visited;
    vector<int>dx={0,1,0,-1};
    vector<int>dy={1,0,-1,0};
    int idx=0;
    int x=0;
    int y=0;
    int n=instructions.size();
     visited.insert({x,y});
     int cnt=0;
     bool f=true;

    for(int i=0;i<100*n;i++){
        if(instructions[i%n]=='G'){  
            f=false;
            x=x+dx[idx];
            y=y+dy[idx];
            if(visited.find({x,y})!=visited.end()) cnt++;
            else{
                cnt=0;
                visited.insert({x,y});
            }
            if(cnt==visited.size()) return true;
            
        }
        else if(instructions[i%n]=='R'){
            idx=(idx+1)%4;
        }
        else idx=(4+idx-1)%4;

        
       
    }
    return f;
   
        
    }
};