class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        deque<int> deq;
        
        for(int i = 0; i < arr.size(); i++)
        {
            deq.push_back(arr[i]);
            if(deq.size() > k)
            {
                if(abs(arr[i] - x) > abs(deq.front() - x)) deq.pop_back();
                else if(abs(arr[i] - x) == abs(deq.front() - x)) deq.pop_back();
                else deq.pop_front();
            }
        }
        
        vector<int> result;
        for(auto a : deq)
            result.push_back(a);
        return result;
    }
};