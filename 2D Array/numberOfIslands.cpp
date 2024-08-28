#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void markCurrentIsland(vector<vector<char>>& grid, int x, int y, int r , int c){
        if(x<0 || x>=r || y<0 || y>=c || grid[x][y] != '1'){
            return;
        }

        grid[x][y] = '2';

        markCurrentIsland(grid , x ,y-1, r ,c);  //Left
        markCurrentIsland(grid , x-1 ,y, r ,c);  //Up
        markCurrentIsland(grid , x ,y+1, r ,c);  //Right
        markCurrentIsland(grid , x+1 ,y, r ,c);  //Bottom

    }

    int numIslands(vector<vector<char>>& grid) {
        
        int row = grid.size();
        if(row == 0)    return 0;
        int col = grid[0].size();

        int islandCount = 0;

        for(int i=0 ; i< row ; i++){
            for(int j= 0; j< col ; j++){
                if(grid[i][j] == '1'){
                    markCurrentIsland(grid , i ,j,row, col);
                    islandCount ++;
                }
            }
        }
        return islandCount;
    }
};