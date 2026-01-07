#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isPossible(vector<int>& nums,int n, int k, int mid){
        int studentCount =1;
        int pageSum = 0;

        for(int i=0; i< n; i++){

            if( pageSum + nums[i] <= mid ){
                pageSum+= nums[i];
            }
            else{
                studentCount++;
                if(studentCount > k || nums[i] > mid ){
                    return false;
                }
                pageSum = nums[i];
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int s = 0;
        int sum = 0;
        for( auto it: nums){
            sum+=it;
        }
        int e = sum;
        int mid = s+(e-s)/2;
        int ans = -1;

        while ( s <= e ){
            if( isPossible(nums,n,k, mid) ){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }

            mid = s+ (e-s)/2;
        }
        
        return ans;
    }
};