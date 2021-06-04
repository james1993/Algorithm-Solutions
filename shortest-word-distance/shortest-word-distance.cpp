class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int word1Idx = -1;
        int word2Idx = -1;
        int shortest_distance = INT_MAX;
        
        for(int i = 0; i < wordsDict.size(); i++)
        {
            if(wordsDict[i] == word1) word1Idx = i;
            if(wordsDict[i] == word2) word2Idx = i;
            
            if(word1Idx != -1 && word2Idx != -1)
                shortest_distance = min(shortest_distance, abs(word1Idx - word2Idx));
        }
        
        return shortest_distance;
    }
};