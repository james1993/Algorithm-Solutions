class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> map;
        vector<int> indices;
        for(int i = 0; i < nums.size(); i++)
        {
            if(map.find(target - nums[i]) == map.end())
            {
                map.insert({nums[i], i});
            }
            else
            {
                indices = {i, map.find(target - nums[i])->second};
            }
        }
        return indices;
    }
};