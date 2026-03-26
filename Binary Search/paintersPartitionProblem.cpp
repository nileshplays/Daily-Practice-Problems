#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    bool isPossible(vector<int>& arr, int n, int k, int mid){
        int painterCount= 1;
        int minuteSum = 0;
        
        for( int i =0; i < n ; i++ ){
            
            if(minuteSum + arr[i] <= mid){
                minuteSum += arr[i];
            }
            else{
                painterCount++;
                if (painterCount > k || arr[i]>mid){
                    return false;
                }
                minuteSum = arr[i];
            }
        }
        return true;
    }
  
    int minTime(vector<int>& arr, int k) {
        int n = arr.size();
        int s = 0;
        
        int sum = 0;
        
        for( auto it: arr ){
            sum+= it;
        }
        
        int e = sum;
        int ans = -1;
        int mid = s + (e-s)/2;
        
        while (s <= e ){
            if( isPossible( arr,n,k,mid ) ){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
            
            mid = s +(e-s)/2;
        }
        return ans;
    }
};