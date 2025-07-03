class Solution {
public:
    bool isRobotBounded(string instructions) {

   
    vector<int>dx={0,1,0,-1};
    vector<int>dy={1,0,-1,0};
    int idx=0;
    int x=0;
    int y=0;
    int n=instructions.size();
    

    for(int i=0;i<n;i++){
        if(instructions[i%n]=='G'){  
           
            x=x+dx[idx];
            y=y+dy[idx];
           
        }
        else if(instructions[i%n]=='R'){
            idx=(idx+1)%4;
        }
        else idx=(4+idx-1)%4;

        
       
    }
    return x==0 && y==0 || idx!=0;
   
        
    }
};