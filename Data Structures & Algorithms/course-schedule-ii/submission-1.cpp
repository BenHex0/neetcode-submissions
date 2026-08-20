class Solution {
   public:
    bool dfs(int node, vector<vector<int>>& nodes, vector<int>& visit, vector<int>& order) {
        if (visit[node] == 1) return false;
        if (visit[node] == 2) return true;

        visit[node] = 1;

        for (auto n : nodes[node]) {
            if (!dfs(n, nodes, visit, order)) return false;
        }

        visit[node] = 2;
        order.push_back(node);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> nodes(numCourses);
        for (auto& p : prerequisites) {
            if (p.size() >= 2) nodes[p[0]].push_back(p[1]);
        }

        vector<int> visit(numCourses, 0);
        vector<int> order;
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, nodes, visit, order)) return {};
        }
        return order;
    }
};
