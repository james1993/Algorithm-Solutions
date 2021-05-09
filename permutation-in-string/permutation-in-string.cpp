class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int windowStart = 0, matched = 0;
        unordered_map<char, int> charFrequencyMap;
        for (auto chr : s1) 
        {
            charFrequencyMap[chr]++;
        }
        for (int windowEnd = 0; windowEnd < s2.length(); windowEnd++) 
        {
            char rightChar = s2[windowEnd];
            if (charFrequencyMap.find(rightChar) != charFrequencyMap.end()) 
            {
                charFrequencyMap[rightChar]--;
                if (charFrequencyMap[rightChar] == 0) 
                {  
                    matched++;
                }
            }
            if (matched == (int)charFrequencyMap.size())
            {
                return true;
            }
            if (windowEnd >= s1.length() - 1) 
            {
                char leftChar = s2[windowStart++];
                if (charFrequencyMap.find(leftChar) != charFrequencyMap.end()) 
                {
                    if (charFrequencyMap[leftChar] == 0) 
                    {
                        matched--;
                    }
                    charFrequencyMap[leftChar]++;
                }
            }
        }
        return false;
    }
};