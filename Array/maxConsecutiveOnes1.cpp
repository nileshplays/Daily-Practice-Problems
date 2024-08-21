#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();

        int maxLength = 0;
        int length = 0;
        for(int  i=0 ; i< n; i++){
            if(nums[i] == 1){
                length++;
                maxLength=max(length, maxLength);
            }
            else{
                length =0 ;
            }

        }
        return maxLength;
    }
};