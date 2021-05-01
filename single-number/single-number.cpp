class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x1 = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            x1 ^= nums[i];
        }
        
        return x1;
    }
};