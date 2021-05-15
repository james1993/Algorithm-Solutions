class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() < 2) return intervals;
        
        vector<vector<int>> merged_intervals;
        
        //sort
        sort(intervals.begin(), intervals.end(), 
        [](const vector<int> &x, const vector<int> &y) { return x[0] < y[0]; });
        
        int start = intervals[0][0];
        int end = intervals[0][1];
        
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0] <= end)
            {
                end = max(end,intervals[i][1]);
            }
            else
            {
                merged_intervals.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        
        vector<int> interval;
        interval.push_back(start);
        interval.push_back(end);
        merged_intervals.push_back(interval);
        
        return merged_intervals;
    }
};