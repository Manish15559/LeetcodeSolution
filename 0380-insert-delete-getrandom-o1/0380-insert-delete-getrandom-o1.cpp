class RandomizedSet {
public:
    unordered_map<int, int> presentNum;
    vector<int> nums;
    RandomizedSet() {}

    bool insert(int val) {
        if (presentNum.find(val) != presentNum.end())
            return false;
        nums.push_back(val);
        int length=nums.size();
        presentNum[val] = (length - 1);
        return true;
    }

    bool remove(int val) {
        if (presentNum.find(val) == presentNum.end())
            return false;
        int idx = presentNum[val];
        int length = nums.size();
        if (idx != (length - 1)) {

            presentNum[nums[length-1]] = idx;
            swap(nums[idx], nums[length - 1]);
        }

        nums.pop_back();
        presentNum.erase(val);
        return true;
    }

    int getRandom() {
        int length=nums.size();
        int idx=rand()%length;
        return nums[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */