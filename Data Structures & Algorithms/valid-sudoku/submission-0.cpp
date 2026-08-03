class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            unordered_set<int> check;
            for (int i = 0; i < 9; i++) {
                if (board[row][i] == '.') continue;
                if (check.count(board[row][i])) return false;
                check.insert(board[row][i]);
            }
        }

        for (int col = 0; col < 9; col++) {
            unordered_set<int> check;
            for (int i = 0; i < 9; i++) {
                if (board[i][col] == '.') continue;
                if (check.count(board[i][col])) return false;
                check.insert(board[i][col]);
            }
        }

                for (int square = 0; square < 9; square++) {
            unordered_set<char> check;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int row = (square / 3) * 3 + i;
                    int col = (square % 3) * 3 + j;
                    if (board[row][col] == '.') continue;
                    if (check.count(board[row][col])) return false;
                    check.insert(board[row][col]);
                }
            }
        }
        return true;
    }
};
