#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int maxSum = 0;

        for(int i=0 ;i<n ;i+=2){
            
            int mini = min(nums[i],nums[i+1]);
            maxSum += mini;
        }
        return maxSum;
    }
};