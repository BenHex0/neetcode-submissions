class Solution {
   public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int perimeter = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    int up = (i > 0) ? i - 1 : -1;
                    int down = (i < row - 1) ? i + 1 : -1;
                    int left = (j > 0) ? j - 1 : -1;
                    int right = (j < col - 1) ? j + 1 : -1;
                    int x = 4;
                    if (up != -1 && grid[up][j] == 1) x--;
                    if (down != -1 && grid[down][j] == 1) x--;
                    if (right != -1 && grid[i][right] == 1) x--;
                    if (left != -1 && grid[i][left] == 1) x--;
                    perimeter += x;
                }
            }
        }

        return perimeter;
    }
};