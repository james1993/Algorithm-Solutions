class Solution {
public:
    bool isValid(string s) {
        stack<int> stack;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                stack.push(s[i]);
            else if(s[i] == ')' && !stack.empty())
            {
                if(stack.top() != '(') return false;
                else stack.pop();
            }
            else if(s[i] == ']' && !stack.empty())
            {
                if(stack.top() != '[') return false;
                else stack.pop();
            }
            else if(s[i] == '}' && !stack.empty())
            {
                if(stack.top() != '{') return false;
                else stack.pop();
            }
            else return false;
        }
        
        if(!stack.empty()) return false;
        return true;
    }
};