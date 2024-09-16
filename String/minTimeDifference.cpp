#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        
        vector<int> mint;
        int n =timePoints.size();
        for(int i =0; i< n ;i++){
            int x = stoi(timePoints[i].substr(0,2));
            int y = stoi(timePoints[i].substr(3,2));

            int num = 60*x + y;
            mint.push_back(num);
        }

        sort(mint.begin(), mint.end());

        int minTime = INT_MAX;
        for(int i=0 ; i< mint.size()-1 ; i++){
            int dif = mint[i+1] - mint[i];
            minTime = min(minTime , dif);
        }

        int circularDiff = 1440 + mint[0]- mint[n-1];
        minTime = min(minTime , circularDiff); 

        return minTime;
    }
};