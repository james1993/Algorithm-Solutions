class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols-i; j++)
            {
                swap(matrix[i][j], matrix[rows-1-j][cols-1-i]);
            }
        }
        for(int i = 0; i < rows/2; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                swap(matrix[i][j],matrix[rows-i-1][j]);
            }
        }
    }
};

// [1,2,3]      [9,6,3]
// [4,5,6] =>   [8,5,2]
// [7,8,9]      [7,4,1]

//0,2