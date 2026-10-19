class DisJointSet {
public:
    vector<int> parent;
    vector<int> size;

    DisJointSet(int n) {
        size.resize(n, 0);
        parent.resize(n,0);

        for (int i = 1; i < n; i++)
            parent[i] = i;
    }

    int findUltimateParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionBySize(int node1, int node2) {

        int ultimateParentOfNode1 = findUltimateParent(node1);
        int ultimateParentOfNode2 = findUltimateParent(node2);

        if (ultimateParentOfNode1 == ultimateParentOfNode2)
            return;

        if (size[ultimateParentOfNode1] > size[ultimateParentOfNode2]) {
            size[ultimateParentOfNode1] += size[ultimateParentOfNode2];
            parent[ultimateParentOfNode2] = ultimateParentOfNode1;
           

        } else {
            size[ultimateParentOfNode2] += size[ultimateParentOfNode1];
            parent[ultimateParentOfNode1] = ultimateParentOfNode2;
          
        }
    }
};
class Solution {
public:
    int largestComponentSize(vector<int>& nums) {

        int maxNum = *max_element(nums.begin(), nums.end());

        DisJointSet* graph = new DisJointSet(maxNum + 1);

        for (int node : nums) {

            for (int i = 2; i * i <= node; i++) {
                if(node%i==0){

                graph->unionBySize(i, node);
                graph->unionBySize(node/i, node);
                }
            }
        }

        vector<int> count(maxNum + 1, 0);
        int maximumCount = 0;

        for (auto node : nums) {

            int ultiParentNode = graph->findUltimateParent(node);
            count[ultiParentNode]++;
            maximumCount = max(maximumCount, count[ultiParentNode]);
        }

        return maximumCount;
    }
};
