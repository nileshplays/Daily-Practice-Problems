#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int r =rowSum.size();
        int c =colSum.size();
        vector<vector<int>>ans(r,vector<int>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0 ; j<c ;j++){
                int minimum =min(rowSum[i],colSum[j]);
                rowSum[i] -= minimum;
                colSum[j] -= minimum;
                ans[i][j] = minimum;
            }
        }
         return ans;
    }
};