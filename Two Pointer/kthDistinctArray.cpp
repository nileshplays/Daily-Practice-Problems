#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        vector<string> ans;
        int n = arr.size();
        for(int i=0 ;i< n ;i++){
            int flag = false;
            for(int j=0 ; j< n; j++){
                
                if((i!=j) && arr[i] == arr[j]){
                    flag = true;
                    break;
                }

            }
            if(!flag){
                ans.push_back(arr[i]);
            }
        }
        if(ans.size() >= k){
            return ans[k-1];
        }
        else{
            return "";
        }
    }
};