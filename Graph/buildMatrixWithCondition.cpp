#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& pairs) 
    {
        vector<vector<int>> adj(V + 1);
        for (const auto& pair : pairs) {
            int u = pair[0];
            int v = pair[1];
            adj[u].push_back(v);
        }

        vector<int> indegree(V + 1, 0);
        for (int u = 0; u < adj.size(); ++u) {
            for (int v : adj[u]) {
                ++indegree[v];
            }
        }

        queue<int> queue;
        for (int i = 1; i <= V; ++i) {
            if (indegree[i] == 0) {
                queue.push(i);
            }
        }

        vector<int> res;
        while (!queue.empty()) {
            int node = queue.front();
            queue.pop();
            res.push_back(node);
            for (int neighbour : adj[node]) {
                --indegree[neighbour];
                if (indegree[neighbour] == 0) {
                    queue.push(neighbour);
                }
            }
        }

        if (res.size() != V) {
            return {};
        }

        return res;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions,vector<vector<int>>& colConditions) {
        vector<int> rowToposort = topoSort(k, rowConditions);
        if (rowToposort.empty()) {
            return {};
        }
        vector<int> colToposort = topoSort(k, colConditions);
        if (colToposort.empty()) {
            return {};
        }
        vector<vector<int>> matrix(k, vector<int>(k, 0));
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                if (rowToposort[i] == colToposort[j]) {
                    matrix[i][j] = colToposort[j];
                }
            }
        }
        return matrix;
    }
};
