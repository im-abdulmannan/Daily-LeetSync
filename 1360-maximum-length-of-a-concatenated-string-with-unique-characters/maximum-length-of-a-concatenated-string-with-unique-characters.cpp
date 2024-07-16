class Solution {
public:
    void backtrack_helper(vector<string>& arr, string curr, int start, int& maxLength)
    {
        if(maxLength < curr.length())
        {
            maxLength = curr.length();
        }

        for(int i = start; i < arr.size(); i++)
        {
            if(!isUnique(curr, arr[i]))
            {
                continue;
            }
            backtrack_helper(arr, curr + arr[i], i + 1, maxLength);
        }
    }

    bool isUnique(const string& currString, const string& newString)
    {
        unordered_set<char> charSet;

        for(char ch : newString)
        {
            if(charSet.count(ch) > 0)
                return false;

            charSet.insert(ch);

            if(currString.find(ch) != string::npos)
                return false;
        }

        return true;
    }

    int maxLength(vector<string>& arr) {
        int maxLength = 0;
        backtrack_helper(arr, "", 0, maxLength);
        return maxLength;
    }
};
