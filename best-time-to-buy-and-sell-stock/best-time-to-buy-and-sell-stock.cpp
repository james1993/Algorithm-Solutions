class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1) return 0;
        int current_min = prices[0];
        int current_max = INT_MIN;
        for(int i = 1; i < prices.size(); i++)
        {
            current_min = min(current_min, prices[i]);
            current_max = max(current_max, prices[i]-current_min);
        }
        return current_max;
    }
};