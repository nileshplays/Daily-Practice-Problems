#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> directions={{0,1},{1,0},{0,-1},{-1,0}};
        int n = rows*cols;
        vector<vector<int>> ans(n , vector<int>(2));
        ans[0] = {rStart,cStart};
        
        
        int step =1;
        int count = 1;
        int index = 0;

        while (count < n) {
            for (int i = 0; i < 2; ++i) {
                int drow = directions[index % 4][0];
                int dcol = directions[index % 4][1];
                for (int j = 0; j < step; j++) {
                    rStart += drow;
                    cStart += dcol;
                    if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                        ans[count] = {rStart, cStart};
                        count++
                        ;
                    }
                }
                index++;
            }
            step++;
        }
        return ans;
    }
};