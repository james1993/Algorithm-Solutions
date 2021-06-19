class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0; 
        int r = height.size() - 1;
        int max_area = 0;
        while(l < r)
        {
            max_area = max(max_area, min(height[r],height[l]) * (r-l));
            if(height[l] < height[r]) l++;
            else r--;
        }
        return max_area;
    }
};