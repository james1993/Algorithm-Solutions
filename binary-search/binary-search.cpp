class Solution {
public:
    int search(vector<int>& nums, int target) {
        int first = 0;
        int last = nums.size() - 1;
        while(first <= last)
        {
            int mid = first + (last - first)/2;
            if(nums[mid] == target) return mid;
            else if(target < nums[mid]) last = mid - 1;
            else first = mid+1;
        }
        
        return -1;
    }
};