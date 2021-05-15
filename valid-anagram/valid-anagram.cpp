class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> s_map(26);
        vector<int> t_map(26);
        
        for(int i = 0; i < s.length(); i++)
        {
            s_map[s[i]-'a']++;
        }
        for(int j = 0; j < t.length(); j++)
        {
            t_map[t[j]-'a']++;
        }
        
        for(int i = 0; i < s_map.size(); i++)
        {
            if(s_map[i] != t_map[i]) return false;
        }
        return true;
    }
};