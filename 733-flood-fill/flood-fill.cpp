class Solution {
private:
    void dfs_helper(vector<vector<int>>& image, int row, int col, int newColor, int currColor)
    {
        if(row < 0 || row >= image.size() || col < 0 || col >= image[0].size() || image[row][col] != currColor) {
            return;
        }

        image[row][col] = newColor;

        dfs_helper(image, row, col + 1, newColor, currColor);
        dfs_helper(image, row + 1, col, newColor, currColor);
        dfs_helper(image, row, col - 1, newColor, currColor);
        dfs_helper(image, row - 1, col, newColor, currColor);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int currColor = image[sr][sc];
        if(currColor != color){
            dfs_helper(image, sr, sc, color, currColor);
        }

        return image;
    }
};