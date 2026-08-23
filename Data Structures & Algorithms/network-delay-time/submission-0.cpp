class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adjacencyList(n + 1);

        for (auto& edge : times) {
            int u = edge[0];
            int v = edge[1];
            int t = edge[2];

            adjacencyList[u].push_back({v, t});
        }

        vector<int> dist(n + 1, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        dist[k] = 0;
        q.push({0, k});

        while (!q.empty()) {
            auto [time, node] = q.top();
            q.pop();

            if (time > dist[node]) continue;

            for (auto& neighbor : adjacencyList[node]) {
                int nextNode = neighbor.first;
                int edgeTime = neighbor.second;

                int newTime = time + edgeTime;

                if (newTime < dist[nextNode]) {
                    dist[nextNode] = newTime;
                    q.push({newTime, nextNode});
                }
            }
        }

        int answer = 0;

        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;

            answer = max(answer, dist[i]);
        }

        return answer;
    }
};
