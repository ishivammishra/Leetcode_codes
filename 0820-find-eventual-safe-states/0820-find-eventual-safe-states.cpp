class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int it : graph[i]) {
                adj[it].push_back(i);
            }
        }

        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++) {
            for (int it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(int it : adj[node])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};