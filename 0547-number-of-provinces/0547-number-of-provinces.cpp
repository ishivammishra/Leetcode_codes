class Solution {
public:
    void dfs(int node, vector<int>& visit, vector<vector<int>>& adj) {

        visit[node] = 1;
        for (int it : adj[node]) {
            if (!visit[it]) {
                dfs(it, visit, adj);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 and i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> visit(n, 0);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                cnt++;
                dfs(i, visit, adj);
            }
        }
        return cnt;
    }
};