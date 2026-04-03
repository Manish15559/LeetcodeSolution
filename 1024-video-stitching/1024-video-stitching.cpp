class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end());

        if (clips[0][0] > 0)
            return -1;
           
        int req = 0;
        int limit = 0;
        int currentClip = 0;
        for (auto it : clips) {

            if (it[0] > limit) {
                if(currentClip>=time) return (req+1);
                if (currentClip < it[0])
                    return -1;
                req++;
                limit = currentClip;
               
            }

            currentClip = max(currentClip, it[1]);
        }

        if (currentClip >= time)
            return (req + 1);

        return -1;
    }
};