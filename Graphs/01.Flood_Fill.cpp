#include <bits/stdc++.h>
using namespace std;

// dfs recursion solution

class Solution1
{
public:
    void func(vector<vector<int>> &v, int i, int j, int orig, int color)
    {
        if (v[i][j] == color)
            return;
        if (v[i][j] != color && v[i][j] != orig)
            return;
        v[i][j] = color;
        if (i - 1 >= 0)
            func(v, i - 1, j, orig, color);
        if (i + 1 < v.size())
            func(v, i + 1, j, orig, color);
        if (j - 1 >= 0)
            func(v, i, j - 1, orig, color);
        if (j + 1 < v[0].size())
            func(v, i, j + 1, orig, color);
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        func(image, sr, sc, image[sr][sc], color);
        return image;
    }
};

class Solution2 {
private:
    void dfs(int row, int col, vector<vector<int>>&ans,
     vector<vector<int>>& image, int newColor, int delRow[], int delCol[],
     int iniColor) {
        // color with new color
        ans[row][col] = newColor; 
        int n = image.size();
        int m = image[0].size(); 
        // there are exactly 4 neighbours
        for(int i = 0;i<4;i++) {
            int nrow = row + delRow[i]; 
            int ncol = col + delCol[i]; 
            // check for valid coordinate 
            // then check for same initial color and unvisited pixel
            if(nrow>=0 && nrow<n && ncol>=0 && ncol < m && 
            image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {
                dfs(nrow, ncol, ans, image, newColor, delRow, delCol, iniColor); 
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, 
    int sr, int sc, int newColor) {
        // get initial color
        int iniColor = image[sr][sc]; 
        vector<vector<int>> ans = image; 
        // delta row and delta column for neighbours
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1}; 
        dfs(sr, sc, ans, image, newColor, delRow, delCol, iniColor); 
        return ans; 
    }
};