class DisJointSet {
    vector<int> parent, count;

public:
    DisJointSet(int n) {
        count.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int getCount(int node) { return count[node]; }

    int findUltimateParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUltimateParent(parent[node]);
    }
    void unionByCount(int node1, int node2) {
        int ultimateParentNode1 = findUltimateParent(node1);
        int ultimateParentNode2 = findUltimateParent(node2);
        if (ultimateParentNode1 == ultimateParentNode2)
            return;
        if (count[ultimateParentNode1] > count[ultimateParentNode2]) {
            count[ultimateParentNode1] += count[ultimateParentNode2];
            parent[ultimateParentNode2] = ultimateParentNode1;
        } else {
            count[ultimateParentNode2] += count[ultimateParentNode1];
            parent[ultimateParentNode1] = ultimateParentNode2;
        }
    }
};

class Solution {
public:
    vector<int> groupStrings(vector<string>& words) {
        int n = words.size();
        unordered_map<int, vector<int>> bitmasks;
        for (int i = 0; i < n; i++) {
            int bitmask = 0;
            for (auto ch : words[i]) {
                bitmask |= (1 << (ch - 'a'));
            }
            bitmasks[bitmask].push_back(i);
        }
        DisJointSet* connectedComponent = new DisJointSet(n);
        for (auto [bitmask, idxes] : bitmasks) {
            int len = idxes.size();
            for (int i = 1; i < len; i++)
                connectedComponent->unionByCount(idxes[i - 1], idxes[i]);
            // by addition and removal
            for (int bit = 0; bit < 26; bit++) {
                int newMask = bitmask ^ (1 << bit);

                if (bitmasks.find(newMask) != bitmasks.end()) {
                    connectedComponent->unionByCount(bitmasks[bitmask][0],
                                                   bitmasks[newMask][0]);
                }
            }
            // replace;
            for (int bit1 = 0; bit1 < 26; bit1++) {
                for (int bit2 = 0; bit2 < 26; bit2++) {
                    if (((bitmask >> bit1) & 1) == 1 &&
                        ((bitmask >> bit2) & 1) == 0) {
                        int newMask = bitmask;
                        newMask ^= (1 << bit1);
                        newMask ^= (1 << bit2);
                        if (bitmasks.find(newMask) != bitmasks.end()) {
                            connectedComponent->unionByCount(
                                bitmasks[bitmask][0], bitmasks[newMask][0]);
                        }
                    }
                }
            }
        }

        int component = 0;
        int mx = 0;
        for (int node = 0; node < n; node++) {
            int ultiParent = connectedComponent->findUltimateParent(node);
            if (node != ultiParent)
                continue;
            component++;
            mx = max(mx, connectedComponent->getCount(node));
        }
        return {component, mx};
    }
};