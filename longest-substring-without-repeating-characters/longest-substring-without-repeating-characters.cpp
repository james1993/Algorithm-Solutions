class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int window_start = 0;
        unordered_map<char, int> map;
        int longest = 0;
        
        for(int window_end = 0; window_end < s.length(); window_end++)
        {
            if(map.find(s[window_end]) != map.end()) map[s[window_end]]++;
            else map.insert({s[window_end],1});
            
            while(map[s[window_end]] > 1) //repeating character
            {
                map[s[window_start]]--;
                window_start++;
            }
            longest = max(longest, window_end - window_start + 1);
        }
        
        return longest;
    }
};