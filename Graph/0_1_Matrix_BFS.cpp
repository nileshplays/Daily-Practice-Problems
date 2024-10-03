#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<vector<int>> distance(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;

        // Mark visited and push in the queue
        for(int i =0 ; i < n ;i++){
            for(int j =0; j< m;j++){
                if(mat[i][j] == 0){
                    visited[i][j] = 1;
                    distance[i][j] = 0;
                    q.push({{i,j},0});
                }
            }
        }

        // All four neighbour coordinates;
        int delRow[4] = {-1,0,1,0};
        int delCol[4] = {0,1,0,-1};

        // BFS
        while( !q.empty()){
            pair<pair<int,int>,int> front = q.front();
            q.pop();
            int row = front.first.first;
            int col = front.first.second;
            int steps = front.second;
            distance[row][col] = steps;
            
            for(int i =0 ;i< 4 ;i++){
                int newRow = row +delRow[i];
                int newCol = col +delCol[i];
                if(newRow>=0 &&newRow<n &&newCol>=0 && newCol <m && visited[newRow][newCol] ==0)
                {
                    visited[newRow][newCol] = 1;
                    q.push({{newRow,newCol},steps+1});
                }
            }
        }

        return distance;
    }
};