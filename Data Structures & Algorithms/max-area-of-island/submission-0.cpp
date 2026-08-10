class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
            int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        int maxLand = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid.at(i).at(j) == 1 && !visited[i][j]) {
                    int count = 1;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = true;

                    while (!q.empty()) {
                        auto cur = q.front();
                        q.pop();

                        for (int k = 0; k < 4; k++) {
                            int nr = cur.first + dr[k];
                            int nc = cur.second + dc[k];

                            if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;

                            if (visited[nr][nc] || grid[nr][nc] == 0) continue;

                            visited[nr][nc] = true;
                            q.push({nr, nc});
                            count++;    
                        }
                    }
                    maxLand = (maxLand < count)? count : maxLand;
                }
            }
        }

        return maxLand;
    }
};
