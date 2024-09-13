#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void xoring(vector<int>& arr , int l, int r,vector<int> &ans){

        int x = arr[l];
        if(l == r){
            ans.push_back(arr[l]);
            return;
        }

        for(int i=l; i<r ; i++){
            x = x ^ arr[i+1];
            
        }
        
        ans.push_back(x);
        
    }
  
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {

        vector<int> ans;
        int n = queries.size();

        for(int i=0; i<n ; i++){
            int left = queries[i][0];
            int right = queries[i][1];
            xoring(arr, left , right , ans);
        }

        return ans;
    }
};