class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.size() == 0) return 0;
        vector<int> previousRow = costs[costs.size()-1];

        for (int i = costs.size() - 2; i >= 0; i--) {

            vector<int> currentRow = costs[i];

            currentRow[0] += min(previousRow[1], previousRow[2]);
            currentRow[1] += min(previousRow[0], previousRow[2]);
            currentRow[2] += min(previousRow[0], previousRow[1]);
            previousRow = currentRow;
        }  

        return min(min(previousRow[0], previousRow[1]), previousRow[2]);
    }
};