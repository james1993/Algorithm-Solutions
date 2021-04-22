class Solution {
public:
    bool isPalindrome(string s) {
        int last = s.length() - 1;
        int first = 0;
        while(first < last)
        {
            while(!isalnum(s[first]) && first < last) first++;
            while(!isalnum(s[last]) && first < last) last--;
            
            if(tolower(s[first]) != tolower(s[last]))
                return false;
            first++;
            last--;
            
        }
        return true;
    }
};