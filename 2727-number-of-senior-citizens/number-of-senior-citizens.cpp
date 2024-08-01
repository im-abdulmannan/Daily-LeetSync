class Solution {
public:
    int findingAge(string detail) {
        string str = detail.substr(11, 2);
        return stoi(str);
    }
    int countSeniors(vector<string>& details) {
        int count = 0;

        for(int i = 0; i < details.size(); i++) {
            if(findingAge(details[i]) > 60) {
                count++;
            }
        }

        return count;
    }
};