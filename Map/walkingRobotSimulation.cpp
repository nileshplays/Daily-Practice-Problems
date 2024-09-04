#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // 0: North, 1: East, 2: South, 3: West
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // constant
        vector<int> curPos = {0, 0};
        int res = 0;
        int curDir = 0; 
        unordered_map<int, unordered_set<int>> obstacleMap; // O(N)
        
        for (auto& obstacle : obstacles) { // O(N)
            obstacleMap[obstacle[0]].insert(obstacle[1]);
        }

        for (int command : commands) { // K
            if (command == -1) {
                // Turn right
                curDir = (curDir + 1) % 4;
                continue;
            }
            if (command == -2) {
                // Turn left
                curDir = (curDir - 1);
                if (curDir == -1) {
                    curDir = 3;
                }
                continue;
            }

            // Move forward
            vector<int> direction = directions[curDir];
            for (int step = 0; step < command; step++) { // 9
                int nextX = curPos[0] + direction[0];
                int nextY = curPos[1] + direction[1];
                if (obstacleMap[nextX].count(nextY)) {
                    break;
                }
                curPos[0] = nextX;
                curPos[1] = nextY;
            }

            res = max(res, curPos[0] * curPos[0] + curPos[1] * curPos[1]);
        }
        
        return res;
    }
};