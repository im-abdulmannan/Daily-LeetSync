class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;

        for(int r = 0; r < board.size(); r++) {
            for(int c = 0; c < board[0].size(); c++) {
                char cell = board[r][c];

                if(cell == '.') continue;

                string row = "row" + to_string(r) + " " + cell;
                string col = "col" + to_string(c) + " " + cell;
                string box = "box" + to_string(r / 3) + "-" + to_string(c / 3) + " " + cell;

                if(seen.count(row) || seen.count(col) || seen.count(box)) return false;

                seen.insert(row);
                seen.insert(col);
                seen.insert(box);
            }
        }

        // for(auto see : seen) {
        //     cout << see << endl;
        // }

        return true;
    }
};
