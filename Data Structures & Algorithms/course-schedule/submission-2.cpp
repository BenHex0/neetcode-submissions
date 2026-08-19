class Solution {
   public:
    bool dfs(int node, vector<vector<int>>& nodes, vector<int>& state, vector<int>& order) {
        if (state[node] == 2) return true;
        if (state[node] == 1) return false;

        state[node] = 1;

        for (int n : nodes[node]) {
            if (!dfs(n, nodes, state, order)) return false;
        }

        state[node] = 2;
        order.push_back(node);

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>> prerequisites) {
        vector<vector<int>> nodes(numCourses);

        for (auto& prerequisite : prerequisites) {
            int course = prerequisite[0];
            int prerequisiteCourse = prerequisite[1];
            nodes[prerequisiteCourse].push_back(course);
        }

        vector<int> state(numCourses, 0);
        vector<int> order;

        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                if (!dfs(i, nodes, state, order))
                    return false;
            }
        }

        reverse(order.begin(), order.end());

        cout << "Topological order: ";
        for (int x : order) cout << x << ' ';
        cout << '\n';

        return true;
    }
};
