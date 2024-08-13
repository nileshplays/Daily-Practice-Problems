#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<int>& candidate, int target, int idx, vector<int> &path, vector<vector<int>>& ret){
        if(target <= 0){
            if(target == 0)
                ret.push_back(path);
            return;
        }

        for(int i=idx; i<candidate.size() ;i++){
            if(i > idx && candidate[i] ==candidate[i-1])
                continue;
            path.push_back(candidate[i]);
            solve(candidate , target- candidate[i], i+1 ,path, ret);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> path;
        sort(candidates.begin(), candidates.end());

        solve(candidates, target, 0, path, ret);
        return ret;
    }
};