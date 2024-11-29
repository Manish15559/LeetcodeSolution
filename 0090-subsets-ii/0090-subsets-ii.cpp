class Solution {
public:
void generateSubsets(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
    // Add the current subset to the result
    result.push_back(current);

    // Iterate over the elements starting from the current index
    for (int i = index; i < nums.size(); i++) {
        // Skip duplicates
        if (i > index && nums[i] == nums[i - 1]) continue;

        // Include the current element and move to the next
        current.push_back(nums[i]);
        generateSubsets(i + 1, nums, current, result);

        // Backtrack by removing the last added element
        current.pop_back();
    }
}

vector<vector<int>> findSubsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;

    // Sort the array to handle duplicates and ensure sorted subsets
    sort(nums.begin(), nums.end());

    // Generate all subsets
    generateSubsets(0, nums, current, result);

    // Sort subsets by size and lexicographically
    sort(result.begin(), result.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a.size() == b.size()) return a < b; // Lexicographical order for subsets of the same size
        return a.size() < b.size(); // Smaller subsets come first
    });

    return result;
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        return findSubsets(nums);
        
    }
};