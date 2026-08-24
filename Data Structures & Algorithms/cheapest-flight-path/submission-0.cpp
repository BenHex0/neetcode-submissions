class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
         vector<vector<pair<int, int>>> adj(n);
    for (auto &f : flights)
        adj[f[0]].push_back({f[1], f[2]});

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    pq.push({0, src, 0}); // {cost, node, stopsUsed}
    vector<int> bestStops(n, INT_MAX);

    while (!pq.empty())
    {
        auto [cost, node, stops] = pq.top();
        pq.pop();

        if (node == dst)
            return cost;
        if (stops > k || stops >= bestStops[node])
            continue;
        bestStops[node] = stops;

        for (auto &[next, price] : adj[node])
            pq.push({cost + price, next, stops + 1});
    }
    return -1;
    }
};
