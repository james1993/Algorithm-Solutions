class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size() < 2) return {};
	    vector<int> result(2);// = {-1, -1};
	    int min_unsorted = nums[0] > nums[1] ? nums[0] : INT_MAX;
	    int max_unsorted = nums[0] > nums[1] ? nums[0] : INT_MIN;
        for(int i = 1; i < nums.size()-1; i++)
	    {
		    if(nums[i] < nums[i-1] || nums[i] > nums[i+1])
		    {
			    min_unsorted = min(min_unsorted,nums[i]);
			    max_unsorted = max(max_unsorted,nums[i]);
		    }
	    }
	    if(nums[nums.size()-1] < nums[nums.size()-2])
	    {
		    min_unsorted = min(min_unsorted,nums[nums.size()-1]);
		    max_unsorted = max(max_unsorted,nums[nums.size()-1]);
	    }
	
	    for(int i = 0; i < nums.size(); i++)
	    {
		    if(min_unsorted < nums[i])
		    {
			    result[0] = i;
			    break;
		    }
	    }
	    for(int i = nums.size() - 1; i >= 0; i--)
	    {
		    if(max_unsorted > nums[i])
		    {
			    result[1] = i;
			    break;
		    }
	    }
	
        return result[1] - result[0] > 0 ? result[1] - result[0] + 1 : 0;
    }
};