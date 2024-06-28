// class Solution {
// public:
//     string removeStars(string s) {

//     }
// };

class Solution {
public:
    string removeStars(string s) {
        string result = "";

        for(auto c : s) {
            if(c == '*') {
                if(!result.empty()) {
                    result.pop_back();
                }
            }
            else
            {
                result.push_back(c);
            }
        }

        return result;
    }
};