class Solution {
public:
    int get_next(vector<vector<int>> mat, int& m, int& n)
    {
        int res = mat[m][n];
        if(m < mat.size() && n >= mat[m].size()-1) 
        {
            n = 0;
            m++;
        }
        else n++;
        
        return res;
        
    }
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if(r*c != mat.size()*mat[0].size()) return mat;
        vector<vector<int>> resized(r,vector<int>(c));
        int m = 0;
        int n = 0;
        
        for(int i = 0; i < resized.size(); i++)
        {
            for(int j = 0; j < resized[i].size(); j++)
            {
                resized[i][j] = get_next(mat, m, n);
            }
        }
        
        return resized;
    }
};