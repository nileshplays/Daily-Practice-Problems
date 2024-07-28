#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            int a = edge[0], b = edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<vector<int>> timeTaken(n + 1, vector<int>(2, INT_MAX)); //visited for 1st and 2nd time

        queue<vector<int>> q;
        timeTaken[1][0] = 0;
        q.push({1, 0});

        while (!q.empty()) {
            auto element = q.front();
            q.pop();
            int node = element[0];
            int curTime = element[1];
            if (node == n) {
                if (timeTaken[node][1] != INT_MAX) {
                    break;
                }
            }

            // If signal is red, add wait time and keep moving
            if ((curTime / change) % 2 != 0) {
                int waitTime = change - (curTime % change);
                curTime = curTime + waitTime + time;
            } else { // If signal is green, keep moving
                curTime = curTime + time;
            }

            for (int neighbour : adj[node]) {
                // First time visit
                if (timeTaken[neighbour][0] == INT_MAX) {
                    timeTaken[neighbour][0] = curTime;
                    q.push({neighbour, curTime});
                }
                // Second time visit but at different level
                else if (timeTaken[neighbour][1] == INT_MAX && curTime > timeTaken[neighbour][0]) {
                    timeTaken[neighbour][1] = curTime;
                    q.push({neighbour, curTime});
                }
            }
        }
        return timeTaken[n][1];
    }
};
