class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            busyRooms;
        priority_queue<int, vector<int>, greater<int>> freeRooms;
        vector<int> meetingHelds(n, 0);
        sort(meetings.begin(), meetings.end());
        for (int i = 0; i < n; i++)
            freeRooms.push(i);
        for (auto meeting : meetings) {
            int startTime = meeting[0];
            int endTime = meeting[1];
            while (!busyRooms.empty() && busyRooms.top().first <= startTime) {
                int roomNo = busyRooms.top().second;
                busyRooms.pop();

                freeRooms.push(roomNo);
            }
            if (!freeRooms.empty()) {
                int freeRoomNo = freeRooms.top();
                freeRooms.pop();
                busyRooms.push({endTime, freeRoomNo});
                meetingHelds[freeRoomNo]++;
            } else {
                int roomNo = busyRooms.top().second;
                long long availableTime = busyRooms.top().first;
                busyRooms.pop();
                busyRooms.push(
                    {availableTime + (endTime - startTime), roomNo});
                meetingHelds[roomNo]++;
            }
        }

        int highestMeetingHeldRoom = 0;
        for (int i = 0; i < n; i++) {

            if (meetingHelds[i] > meetingHelds[highestMeetingHeldRoom]) {
                highestMeetingHeldRoom = i;
            }
        }
        return highestMeetingHeldRoom;
    }
};