class Solution {
public:
    string minWindow(string s, string t) {
        int window_start = 0;
        int minimum_window = INT_MAX;
        int minimum_index = 0;
        unordered_map<char,int> t_map;
        unordered_map<char,int> s_map;
        for(int i = 0; i < t.length(); i++)
        {
            if(t[i] < 'a') t_map[t[i]]++;
            else t_map[t[i]]++;
            s_map[t[i]] = 0;
        }
        
        int t_map_size = t_map.size();
        int match_count = 0;
        
        for(int window_end = 0; window_end < s.length(); window_end++)
        {
            if(s_map.find(s[window_end]) != s_map.end()) 
            {
                s_map[s[window_end]]++;
                if(s_map[s[window_end]] == t_map[s[window_end]])
                {
                    match_count++;
                }
            }  
            while(match_count == t_map_size)
            {
                if(minimum_window >= window_end-window_start+1)
                {
                    minimum_window = window_end-window_start+1;
                    minimum_index = window_start;
                }
                if(s_map.find(s[window_start]) != s_map.end()) 
                {
                    s_map[s[window_start]]--;
                    if(s_map[s[window_start]] < t_map[s[window_start]]) 
                        match_count--;
                }
                window_start++;
            }
            
        }
        return minimum_window == INT_MAX ? "" : s.substr(minimum_index,minimum_window);
    }
};