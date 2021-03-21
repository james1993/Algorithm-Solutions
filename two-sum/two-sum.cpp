class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> compliments;
        vector<int> indices(2);
        for(int i = 0; i < nums.size(); i++)
        {
            auto iter = compliments.find(target-nums[i]);
            if(iter == compliments.end())
                compliments.insert({nums[i],i});
            else
            {
                indices[0] = (*iter).second;
                indices[1] = i;
                break;
            }
        }
        
        return indices;
    }
};