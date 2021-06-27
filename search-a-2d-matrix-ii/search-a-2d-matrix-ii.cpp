class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size()-1;
        int col = 0;

        while(row >= 0 && col < matrix[0].size())
        {
            if(target < matrix[row][col]) row--;
            else if(target > matrix[row][col]) col++;
            else return true;
        }
        return false;
    }
};