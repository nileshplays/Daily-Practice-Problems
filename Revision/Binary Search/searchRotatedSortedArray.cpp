#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size()-1;
        int s = 0, e = n;
        
        while(s < e){
            int mid = s + (e-s)/2;
            if( nums[mid] > nums[e] )
            {
                s = mid+1;
            }
            else{
                e = mid;
            }
        }
        int pivot = s;

        if(nums[pivot] <= target && target <= nums[n]){
            s = pivot;
            e = n;
        }
        else{
            s = 0;
            e = pivot -1;
        }

        while(s <= e){
            int mid = s+(e-s)/2;
            if(nums[mid] > target){
                e = mid-1;
            }
            else if(nums[mid] < target){
                s = mid+1;
            }
            else{
                return mid;
            }
        }

        return -1;
    }
};