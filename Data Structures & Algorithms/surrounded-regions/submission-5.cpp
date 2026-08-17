class Solution {
   public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O') {
                    queue<pair<int, int>> q;
                    q.push({i, j});

                    vector<vector<bool>> visited(row, vector<bool>(col, false));
                    visited[i][j] = true;

                    bool surrounded = true;

                    vector<vector<bool>> capture(row, vector<bool>(col, false));
                    capture[i][j] = true;

                    while (!q.empty()) {
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();

                        capture[r][c] = true;

                        if (r == 0 || r == row - 1 || c == 0 || c == col - 1) surrounded = false;

                        for (int k = 0; k < 4; k++) {
                            int nr = r + dr[k];
                            int nc = c + dc[k];

                            if (nr < 0 || nr >= row || nc < 0 || nc >= col || visited[nr][nc] ||
                                board[nr][nc] == 'X')
                                continue;

                            q.push({nr, nc});
                            visited[nr][nc] = true;
                        }
                    }

                    if (surrounded) {
                        for (int w = 0; w < row; w++) {
                            for (int z = 0; z < col; z++) {
                                if (capture[w][z]) board[w][z] = 'X';
                            }
                        }
                    }
                }
            }
        }
    }
};
