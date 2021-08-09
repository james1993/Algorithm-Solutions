struct word_unit{
    string word;
    int freq;
};
class Compare{
    public:
    bool operator() (word_unit& a, word_unit& b)
    {
        if(a.freq == b.freq)
        {
            return a.word > b.word;
        }
        else
            return a.freq < b.freq;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> frequencies;
        priority_queue<word_unit,vector<word_unit>, Compare> max_heap;
        vector<string> result;
        
        for(int i = 0; i < words.size(); i++)
            frequencies[words[i]]++;
        
        for(auto element : frequencies)
        {
            word_unit a;
            a.word = element.first;
            a.freq = element.second;
            max_heap.push(a);
        }
        
        while(k)
        {
            result.push_back(max_heap.top().word);
            max_heap.pop();
            k--;
        }
        //sort(result.begin(),result.end());
        return result;
    }
};