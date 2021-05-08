class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int min_candies = INT_MAX;
        int max_candies = INT_MIN;
        vector<bool> is_greatest;
        for(int i = 0; i < candies.size(); i++)
            max_candies = max(max_candies, candies[i]);
        
        for(int i = 0; i < candies.size(); i++)
        {
            if(candies[i]+extraCandies >= max_candies)
            {
                is_greatest.push_back(true);
            }
            else
            {
                is_greatest.push_back(false);
            }
        }
        
        return is_greatest;
    }
};