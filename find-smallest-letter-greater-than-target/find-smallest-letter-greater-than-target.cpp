class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int first = 0;
        int last = letters.size() - 1;
        
        while(first <= last)
        {
            int mid = first + (last - first)/2;
            if(target < letters[mid]) 
                last = mid - 1;
            else if(target > letters[mid]) 
                first = mid + 1;
            else 
            {
                first = mid;
                break;
            }
        }
        while(letters[first] == target) 
            first++;
        
        cout << "letters[first] = " << letters[first] << "\n";
        if(target >= letters[first]) 
        {
            if(first + 1 > letters.size() - 1)
                return letters[0];
            else
                return letters[first+1];
        }
        else
            return letters[first];
    }
};

//first = 0
//last = 0
//mid = 1