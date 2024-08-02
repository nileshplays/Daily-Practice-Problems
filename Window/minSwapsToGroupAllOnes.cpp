#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
        int windowSize = 0;
        //counting no. of ones
        for(auto num: nums){
            windowSize += num;
        }
        //find zeros in 1st window
        int currZero = 0;
        for(int i =0; i< windowSize; i++){
            if(nums[i] == 0)    
                currZero++;
        }
        //remaining vector
        int minZero = currZero;
        int start = 0;
        int end = windowSize-1;
        int size = nums.size();
        for(int i =start ; i<size ;i++){
            //If removed element is 0 decrement zero Counter
            if(nums[start] == 0)
                currZero--;
            start++;
            //If included element is 0 then increment zero Counter
            end++;
            if(nums[end%size] == 0){
                currZero++;
            }
            minZero = min(currZero, minZero);
        }
        return minZero;
    }
};