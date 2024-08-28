#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int rows;
    int cols;
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    bool dfs(int row, int col, vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<bool>>& visited) {
        visited[row][col] = true;
        bool isIsland = true;

        // If grid1's corresponding cell is water, mark as not an island
        if (grid1[row][col] == 0) {
            isIsland = false;
        }

        // Visit neighboring cells
        for (const auto& dir : dirs) {
            int nextR = row + dir[0];
            int nextC = col + dir[1];
            if (nextR >= 0 && nextC >= 0 && nextR < rows && nextC < cols && grid2[nextR][nextC] == 1 && !visited[nextR][nextC]) {
                bool res = dfs(nextR, nextC, grid1, grid2, visited);
                isIsland = isIsland && res;
            }
        }
        return isIsland;
    }

public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        rows = grid1.size();
        cols = grid1[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int count = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!visited[i][j] && grid2[i][j] == 1) {
                    if (dfs(i, j, grid1, grid2, visited)) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};