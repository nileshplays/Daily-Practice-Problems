#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum_m = 0;
        vector<int> ans(n,0);

        for(auto i : rolls){
            sum_m += i;
        }
        int m =rolls.size();
        int sum_n = mean*(m+n) - sum_m;

        if(sum_n < 0 || sum_n <n)
            return {};
        
        int x= sum_n;
        for(int i=0 ; i<x ; i= (i+1)%n){
            if(sum_n == 0)  
                return ans;
            
            ans[i]+= 1;
            sum_n -=1;
            if(ans[i] > 6)
                return {};
        }
        return ans;
    }
};