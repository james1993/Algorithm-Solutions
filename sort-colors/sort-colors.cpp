class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero_index = 0;
        int two_index = nums.size()-1;
        int i = 0;
        
        while(i <= two_index)
        {
            if(nums[i] == 0)
            {
                swap(nums[i++],nums[zero_index++]);
            }
            else if(nums[i] == 2)
            {
                swap(nums[i],nums[two_index--]);
            }
            else i++;
        }
    }
};

/*
0,0,1,1,2,2
    ^ ^
i = 2
*/