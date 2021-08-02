class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> ltr_distance(s.length(),s.length()-1);
        vector<int> rtl_distance(s.length(),s.length()-1);
        vector<int> result(s.length());
        
        int idx_last_seen = s.length()+s.length();
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == c)
            {
                idx_last_seen = i;
                ltr_distance[i] = 0;
            }
            else
            {
                ltr_distance[i] = abs(i-idx_last_seen);
            }
        }
        idx_last_seen = s.length()+s.length();
        for(int i = s.length()-1; i >= 0; i--)
        {
            if(s[i] == c)
            {
                idx_last_seen = i;
                rtl_distance[i] = 0;
            }
            else
            {
                rtl_distance[i] = abs(i-idx_last_seen);
            }
        }
        for(int i = 0; i < s.length(); i++)
        {
            result[i] = min(rtl_distance[i],ltr_distance[i]);
        }
        return result;
    }
};