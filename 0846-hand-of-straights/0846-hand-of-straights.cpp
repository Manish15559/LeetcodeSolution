class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(), hand.end(), greater<int>());
        unordered_map<int, int> countHands;
        for (auto handNum : hand)
            countHands[handNum]++;
        for (auto handNum : hand) {
            int count = groupSize;
            int currValue = handNum;
            if (countHands.find(currValue) == countHands.end()) continue;
            while (count > 0) {
                if (countHands.find(currValue) == countHands.end())
                    return false;
                count--;
                countHands[currValue]--;
                if (countHands[currValue] == 0)
                    countHands.erase(currValue);
                currValue--;
            }
        }
        return true;
    }
};