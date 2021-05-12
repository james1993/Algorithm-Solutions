class Solution {
public:
    void recurse(int i, vector<int> nums, vector<vector<int>>& result)
    {
	  if(i == nums.size() - 1) result.push_back(nums);
	  else
	  {
		  for(int j = i; j < nums.size(); j++)
		  {
			  swap(nums[i], nums[j]);
			  recurse(i+1, nums, result);
			  swap(nums[i], nums[j]);
		  }
	  }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
	    recurse(0, nums, result);
        return result;
    }
};

