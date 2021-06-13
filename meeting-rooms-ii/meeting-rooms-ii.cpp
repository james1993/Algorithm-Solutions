class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), [](vector<int> x, vector<int> y) {return x[0] < y[0]; });
        
        priority_queue <int, vector<int>, greater<int> > min_heap;
        int max_rooms = 1;
        min_heap.push(intervals[0][1]);
        
        for(int i = 1; i < intervals.size(); i++)
        {
            /*
            while (!minHeap.empty() && meeting.start >= minHeap.top().end) {
        minHeap.pop();
      }
      // add the current meeting into the minHeap
      minHeap.push(meeting);
      // all active meeting are in the minHeap, so we need rooms for all of them.
      minRooms = max(minRooms, (int)minHeap.size());
    }

    return minRooms;
            */
            while(!min_heap.empty() && intervals[i][0] >= min_heap.top()) 
            {
                min_heap.pop();
            }
            
            min_heap.push(intervals[i][1]);


            max_rooms = max(max_rooms, (int)(min_heap.size()));
        }
        
        return max_rooms;
    }
};