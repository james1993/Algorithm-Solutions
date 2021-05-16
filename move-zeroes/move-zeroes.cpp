class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroCount = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
                zeroCount++;
            else if(zeroCount)
            {
                int temp = nums[i-zeroCount];
                nums[i-zeroCount] = nums[i];
                nums[i] = 0;
            }
            
        }
    }
};