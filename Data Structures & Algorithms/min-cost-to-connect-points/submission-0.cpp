class Solution {
   public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<vector<pair<int, int>>> adjacencyList(n);

        for (int i = 0; i < points.size(); i++) {
            int xi = points[i][0];
            int yi = points[i][1];
            for (int j = 0; j < points.size(); j++) {
                if (i == j) continue;
                int xj = points[j][0];
                int yj = points[j][1];

                int cost = abs(xi - xj) + abs(yi - yj);
                adjacencyList[i].push_back({j, cost});
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> visits(n, 0);
        pq.push({0, 0});

        int totalCosts = 0;
        int nodeCount = 0;
        while (!pq.empty() && nodeCount < n) {
            int node = pq.top().second;
            int cost = pq.top().first;
            pq.pop();

            if (visits[node]) continue;

            visits[node] = 1;

            totalCosts += cost;
            nodeCount++;

            for (auto n : adjacencyList[node]) {
                if (!visits[n.first]) {
                    pq.push({n.second, n.first});
                }
            }
        }

        return totalCosts;
    }
};
