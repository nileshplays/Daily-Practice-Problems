#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        
        vector<int> results;
        priority_queue<int> maxi;

        int r = queries.size();
        int c = queries[0].size();
        for(int i=0 ; i<r ; i++){

            int sum =0;
            for(int j=0; j<c ; j++){
                sum += abs(queries[i][j]);
            }
            
            if(maxi.size() < k){
                maxi.push(sum);
            }
            else{
                if(sum < maxi.top()){
                    maxi.pop();
                    maxi.push(sum);
                }
            }

            if(maxi.size() >= k){
                results.push_back(maxi.top());
            }

            else{
                results.push_back(-1);
            }

        }
        return results;
    }
};