class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        //if(nums.size() < 2) return nums;
        vector<int> sorted_squares(nums.size());
        
        for(int i = 0; i < nums.size(); i++)
        {
            nums[i] *= nums[i];
        }
        
        int first = 0;
        int last = nums.size() - 1;
        int insert_index = sorted_squares.size() - 1;
        
        while(first <= last)
        {
            if(nums[first]>= nums[last])
            {
                sorted_squares[insert_index] = nums[first];
                first++;
            }
            else
            {
                sorted_squares[insert_index] = nums[last];
                last--;
            }
            insert_index--;
        }
        
        return sorted_squares;
    }
};