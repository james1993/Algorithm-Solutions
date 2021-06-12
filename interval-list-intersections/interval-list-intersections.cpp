class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> intersections;
        
        int i = 0;
        int j = 0;
        
        while(i < firstList.size() && j < secondList.size())
        {
            if((secondList[j][0] <= firstList[i][1] && secondList[j][0] >= firstList[i][0]) ||
               (firstList[i][0] <= secondList[j][1] && firstList[i][0] >= secondList[j][0]))
            {
                //overlaps
                int start = max(firstList[i][0], secondList[j][0]);
                int end = min(firstList[i][1], secondList[j][1]);
                intersections.push_back({start, end});
            }
            
            if(firstList[i][1] < secondList[j][1]) i++;
            else j++;
        }
        return intersections;
    }
};