class DisJointSet {
    vector<int> parent;
    vector<int> rank;

public:
    DisJointSet(int n) {
        parent.resize(n, 0);
        rank.resize(n, 1);
        for (int node = 0; node < n; node++)
            parent[node] = node;
    }
    int findUltimateParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUltimateParent(parent[node]);
    }
    void unionByRank(int node1, int node2) {
        int ultiParentNode1 = findUltimateParent(node1);
        int ultiParentNode2 = findUltimateParent(node2);
        if (ultiParentNode1 == ultiParentNode2)
            return;
        if (rank[ultiParentNode1] > rank[ultiParentNode2]) {
            parent[ultiParentNode2] = ultiParentNode1;
            rank[ultiParentNode1]++;
        } else {
            parent[ultiParentNode1] = ultiParentNode2;
            rank[ultiParentNode2]++;
        }
    }
};

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        DisJointSet* connectedLands = new DisJointSet((row * col) + 2);
        for (int c = 0; c < col; c++) {
            connectedLands->unionByRank(0, (c + 1));
            connectedLands->unionByRank((row * col + 1),
                                        (row - 1) * col + c + 1);
        }
        vector<vector<int>> vis(row, vector<int>(col, 0));
        for (int day = (row * col); day >= 1; day--) {
            int r = cells[day - 1][0];
            int c = cells[day - 1][1];
            r--;
            c--;
            int node = (r * col) + (c + 1);
            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};
            for (int idx = 0; idx < 4; idx++) {
                int nrow = r + dx[idx];
                int ncol = c + dy[idx];
                if(!(nrow>=0&&ncol>=0&&nrow<row&&ncol<col)) continue;
                int adjNode = (nrow * col) + ncol + 1;
                if (!vis[nrow][ncol])
                    continue;
                connectedLands->unionByRank(node, adjNode);
                if (connectedLands->findUltimateParent(0) ==
                    connectedLands->findUltimateParent(row * col + 1))
                    return (day - 1);
            }
            vis[r][c] = 1;
        }
        return 0;
    }
};