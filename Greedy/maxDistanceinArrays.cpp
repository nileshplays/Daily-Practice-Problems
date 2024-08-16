#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {

        int rows= arrays.size();
        // int cols = arrays[0].size();

        int small = arrays[0][0];
        int big = arrays[0].back();

        int maxi = 0;    
        for(int i=1 ; i<rows ; i++){
            int first = small-arrays[i].back();
            int second = big-arrays[i][0];
            int localMax = max(abs(first),abs(second));
            maxi = max(maxi , localMax);

            small = min(small, arrays[i][0]);
            big = max(big, arrays[i].back());

        } 
        return maxi;
    }
};