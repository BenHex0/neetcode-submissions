class Solution {
   public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<vector<int>> adjacencyList(n + 1);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            // Check if there is already a path from u to v
            vector<bool> visited(n + 1, false);
            queue<int> q;

            q.push(u);
            visited[u] = true;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                if (node == v) return edge;

                for (int neighbor : adjacencyList[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }

            adjacencyList[u].push_back(v);
            adjacencyList[v].push_back(u);
        }

        return {};
    }
};
