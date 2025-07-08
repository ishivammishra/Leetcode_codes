class Solution {
public:

    void dfs(int node, vector<int> &visited, vector<vector<int>> &adj)
    {
        visited[node] = 1;
        for(int it : adj[node])
        {
            if(!visited[it])
            {
                dfs(it, visited, adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        // converting matrix into list
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 and i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> visited(n, 0);
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                cnt++;
                dfs(i, visited, adj);
            }
        }
        return cnt;
    }
};