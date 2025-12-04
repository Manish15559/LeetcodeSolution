class Solution {
public:
    
    int countCollisions(string directions) {
        int state=-1;  //0-stationay car, 1-> car is moving right,-1-> //no car on left;
        int count=0;
        for(auto direction:directions){
            if(direction=='L'){
                if(state!=-1){
                    count+=(state+1);
                    state=0;

                }
            }
            else if(direction=='S'){
                if(state==-1) state=0;
                else {
                    count+=(state);
                    state=0;
                }
            }
            else{
                if(state==-1) state=1;
                else state++;
            }
        }

        return count;

        
        
    }
};