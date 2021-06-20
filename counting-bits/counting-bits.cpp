class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bit_counts;
        for(int i = 0; i <= n; i++)
        {
            int count = 0;
            int dummy = i;
            //count bits
            while(dummy)
            {
                count += dummy & 1;
                dummy >>= 1;
            }
            
            bit_counts.push_back(count);
        }
        
        return bit_counts;
    }
};