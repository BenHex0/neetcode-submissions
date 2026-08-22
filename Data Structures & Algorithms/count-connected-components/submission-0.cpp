class Solution {
   public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjacencyList(n);

        for (int i = 0; i < edges.size(); i++) {
            if (edges[i].size() >= 2) {
                int u = edges[i][0];
                int v = edges[i][1];

                adjacencyList[u].push_back(v);
                adjacencyList[v].push_back(u);
            }
        }

        vector<bool> visit(n);
        queue<int> q;
        q.push(0);
        visit[0] = true;
        int count = 1;

        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                count++;
                q.push(i);
            }

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int n : adjacencyList[node]) {
                    if (visit[n]) continue;

                    visit[n] = true;
                    q.push(n);
                }
            }
        }

        return count;
    }
};
