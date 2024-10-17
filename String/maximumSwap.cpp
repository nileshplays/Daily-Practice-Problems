#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        vector<int> rightMax(n);
        int maxPos = n-1;
        rightMax[n-1] = n-1;

        for(int i = n-2; i>=0; i--){
            if(s[i] > s[maxPos]){
                maxPos = i;
            }
            rightMax[i] = maxPos;
        }

        for(int i =0; i< n ;i++){
            if(s[i] != s[rightMax[i]]){
                swap(s[rightMax[i]] , s[i]);
                break;
                // cout<<"S: "<<s<<endl;
            }
        }

        int val = stoi(s);

        return val;
    }
};