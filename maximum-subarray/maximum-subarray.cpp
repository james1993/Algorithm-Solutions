class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];

        int running_sum = 0;
        int max_sum = numeric_limits<int>::min();
        for(int i = 0; i < nums.size(); i++)
        {
            running_sum += nums[i];
            if(nums[i] > running_sum) running_sum = nums[i];
            max_sum = max(running_sum, max_sum);
        }
        return max_sum;
    }
};