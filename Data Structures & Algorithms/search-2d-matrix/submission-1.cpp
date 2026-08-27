class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         for (int i = 0; i < matrix.size(); i++)
    {
        int l = 0;
        int r = matrix[0].size() - 1;

        while (l <= r)
        {
            int c = l + (r - l) / 2;

            if (matrix[i][c] < target)
                l = c + 1;
            else if (matrix[i][c] > target)
                r = c - 1;
            else
                return true;
        }
    }

    return false;
    }
};
