class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer;
        for(int i = 1; i <= n; i++)
        {
            string element = "";
            if(i % 3 == 0) element += "Fizz";
            if(i % 5 == 0) element += "Buzz";
            if(element == "") element += to_string(i);
            
            answer.push_back(element);
        }
        
        return answer;
    }
};