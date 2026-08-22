class Solution {
   public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjacencyList(n);

        for (int i = 0; i < edges.size(); i++) {
            if (edges[i].size() >= 2) {
                int u = edges[i][0];
                int v = edges[i][1];

                adjacencyList[u].push_back(v);
                adjacencyList[v].push_back(u);
            }
        }

        vector<bool> visit(n, false);
        stack<int> st;
        st.push(0);
        visit[0] = true;
        int count = 1;

        while (!st.empty()) {
            int node = st.top();
            st.pop();

            for (int neighbor : adjacencyList[node]) {
                if (!visit[neighbor]) {
                    visit[neighbor] = true;
                    count++;
                    st.push(neighbor);
                }
            }
        }

        return n - 1 == edges.size() && count == n;
    }
};
