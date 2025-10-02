class Solution {
public:
class UsedType{  //type of the meeting room when in used
    public:
    long long freeTime;
    int number;

    UsedType(long long f,int n){
        freeTime=f;
        number=n;
    }

};

class cmp1{
    public :
    bool operator()(UsedType &a,UsedType &b){
        if(a.freeTime!=b.freeTime) return a.freeTime > b.freeTime;
        else return a.number > b.number;
    }
};
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<int,vector<int>,greater<int>> availableRooms;

        priority_queue<UsedType,vector<UsedType>,cmp1> usedRooms;
        sort(meetings.begin(),meetings.end());
        for(int i=0;i<n;i++) availableRooms.push(i);

        vector<int>NumberofMeetings(n,0);
        long long currTime=0;

        for(vector<int> meeting:meetings){
            int startTime=meeting[0];
            int endTime=meeting[1];
            currTime=max(currTime,(long long)startTime);
            while(!usedRooms.empty()&&usedRooms.top().freeTime<=currTime){
                UsedType usedRoom=usedRooms.top();
                usedRooms.pop();
                availableRooms.push(usedRoom.number);
            }
           
            if(availableRooms.empty()){
                currTime=usedRooms.top().freeTime;
                 while(!usedRooms.empty()&&usedRooms.top().freeTime<=currTime){
                UsedType usedRoom=usedRooms.top();
                usedRooms.pop();
                availableRooms.push(usedRoom.number);
            }
            }
            
            int availableRoom =availableRooms.top();
            availableRooms.pop();
            // cout<<startTime<<" "<<availableRoom<<endl;
            usedRooms.push(UsedType((currTime+endTime-startTime),availableRoom));
            NumberofMeetings[availableRoom]++;
                 
            

            }


        
        int ans=0;
        for(auto it:NumberofMeetings) cout<<it<<" ";

        for(int room=1;room<n;room++){
            if(NumberofMeetings[room]>NumberofMeetings[ans]) ans=room;
        }

        return ans;


        
    }
};