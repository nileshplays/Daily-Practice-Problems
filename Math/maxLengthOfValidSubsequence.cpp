#include<bits/stdc++.h>
using namespace std;
class Solution {

public:
    int maximumLength(vector<int>& nums) {
        int evenC=0, oddC=0, alterC = 1;
        for(int i =0; i < nums.size() ; i++){
            if(nums[i] %2 == 0){
                evenC++;
            } 
            else{
                oddC++;
            }
        }
        int maxOddEven = max(evenC,oddC);
        for(int i = 1; i<nums.size() ; i++){
            if((nums[i-1])%2 != (nums[i])%2){
                alterC++;
            }
            else{
                continue;
            }
        }
        return max(maxOddEven,alterC);
    }
};
