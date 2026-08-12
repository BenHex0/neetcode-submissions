class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        int count = 0;
        int rot = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) count++;
            }
        }
        if (count == 0) return 0;
        if (q.empty()) return -1;

        int minute = 0;
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for (int j = 0; j < 4; j++) {
                    int r = row + dirs[j][0];
                    int c = col + dirs[j][1];

                    if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != 1) {
                        continue;
                    }

                    q.push({r, c});
                    grid[r][c] = 2;
                    rot++;
                }
            }

            minute++;
        }

        return rot == count ? minute - 1 : -1;
    }
};
