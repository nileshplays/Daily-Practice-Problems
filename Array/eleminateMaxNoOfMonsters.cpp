#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        
        vector<int> time;
        int count = 0;
        for(int i=0; i<speed.size(); i++){
            if(dist[i] % speed[i] ==0){
                time.push_back(dist[i]/speed[i] );
            }
            else{
                time.push_back((dist[i] /speed[i]) +1);
            }
        }

        sort(time.begin(), time.end());
        
        for(int i=0; i<time.size(); i++){
            if(time[i] - count <= 0){
                return i;
            }
            else{
                count++;
            }
        }
        return time.size();
    }
};