#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int n = nums.size();
        int l =0, r=0 ;
        int maxLength = 0 , zeroes = 0;

        while(r < n){
            if(nums[r] == 0){
                zeroes++;
            }

            //Optimized code
            if(zeroes > k){
                if(nums[l]==0)  
                    zeroes--;
                
                l++;
            }
            // REDUNDUND PART
            /*   
            while(zeroes > k){
                if(nums[l] == 0)
                    zeroes--;
                l++;
            }
            */
            
            if(zeroes <= k){
                int length = r-l+1;
                maxLength = max(maxLength , length);
            }
            r++;
        }
        return maxLength;
    }
};

// #2 Approach   :                 T.C. = O(2n)   ,    S.C. = O(1).
/*
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int n = nums.size();
        int l =0, r=0 ;
        int maxLength = 0 , zeroes = 0;

        while(r < n){
            if(nums[r] == 0){
                zeroes++;
            }

            while(zeroes > k){
                if(nums[l] == 0)
                    zeroes--;
                l++;
            }

            if(zeroes <= k){
                int length = r-l+1;
                maxLength = max(maxLength , length);
            }
            r++;
        }
        return maxLength;
    }
};
*/


//   BRUTE FORCE :                 T.C.= O(n^2)   ,    S.C. = O(1).
/*
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int n= nums.size();
        int maxLength =0;

        for(int i=0 ; i< n ;i++){
            int zero = 0;

            for(int j=i ; j<n ;j++ ){

                if(nums[j] ==0){
                    zero++;

                }
                if(zero <= k){
                    int length = j-i +1;
                    maxLength = max(maxLength , length);
                }
                else{
                    break;
                }
            }
        }

        return maxLength;
    }
};
*/