class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if (matrix.empty()) return ret;
        int move[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };
        bool isSearched[matrix.size()][matrix[0].size()];
        memset(isSearched, false, sizeof(isSearched));
        int m = matrix.size(), n = matrix[0].size();
        int iCol = 0, iRow = 0, direction = 0;
        ret.push_back(matrix[0][0]);
        isSearched[0][0] = true;
        while (ret.size() != m * n) {
            if (iRow + move[direction][0] < 0 || iRow + move[direction][0] >= m ||
                    iCol + move[direction][1] < 0 || iCol + move[direction][1] >= n)
                direction = (direction + 1) % 4;
            else if (isSearched[ iRow + move[direction][0] ][ iCol + move[direction][1] ])
                direction = (direction + 1) % 4;
            iRow += move[direction][0];
            iCol += move[direction][1];
            isSearched[iRow][iCol] = true;
            ret.push_back(matrix[iRow][iCol]);
        }
        return ret;
    }
};
