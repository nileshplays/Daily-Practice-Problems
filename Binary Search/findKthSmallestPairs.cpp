#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int smallestDistancePair(vector<int>& nums, int k){
        sort(nums.begin(),nums.end());
        int low = 0;

        //Define the Search space for distance
        int high = nums.back() - nums.front();

        //Binary Search for kth Smallest pair
        while(low < high){
            int mid = low+ (high-low)/2;
            int left = 0, count = 0;   //Initialize Var for countingpairs and left pointers

            // Count pairs with distance <= mid using a two-pointer technique
            for(int right=0; right<nums.size(); right++){
                while(nums[right]-nums[left] >mid)
                //// Move the left pointer to maintain the condition nums[right] - nums[left] <= mid
                    left++;    
                
                count += right-left;   // Count the number of valid pairs with the current `right` pointer

            }
            // Adjust Search Space based on count
            if(count < k){
                low = mid+1;   //// If count is less than k, search in the upper half
            }
            else{
                high = mid;   // If count is greater than or equal to k, search in the lower half
            }
        }
        return low;
    }
};