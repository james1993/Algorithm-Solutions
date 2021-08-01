class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> counts(101,0);
        int running_sum = 0;
        vector<int> result(nums.size());
        
        for(int i = 0; i < nums.size(); i++)
        {
            counts[nums[i]]++;
        }
        for(int i = 0; i < counts.size(); i++)
        {
            running_sum += counts[i];
            counts[i] = running_sum;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i]-1 < 0) result[i] = 0;
            else result[i] = counts[nums[i]-1];
        }
        return result;
    }
};