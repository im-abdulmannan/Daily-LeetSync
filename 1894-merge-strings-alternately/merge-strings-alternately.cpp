class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        int i = 0;
        int j = 0;

        while(i < word1.length() && j < word2.length()) {
            result = result + word1[i]; 
            result = result + word2[j]; 
            i+=1, j+=1; // i -> 3, j -> 3
        }
        // apbqcr

        while(word1.length() > word2.length() && i < word1.length()) {
            result = result + word1[i];
            i++;
        }
        // apbqcr -- tf from class 1

        while(word2.length() > word1.length() && j < word2.length()) {
            result += word2[j];
            j++;
        }
        // apbqcr -- tf from class 2

        return result;
    }
};