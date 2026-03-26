#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    bool isPossible(vector<int> &stalls, int n, int k, int mid){
        
        int cowCount = 1;
        int lastPosition = stalls[0];
        
        for(int i =1; i <n ; i++){
            if( stalls[i]-lastPosition >= mid ){
                cowCount++;
                
                if( cowCount == k ) {
                    return true;
                }
                lastPosition = stalls[i];
            }
        }
        return false;
    }
  
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(), stalls.end());
        int n = stalls.size();
        int s = 0;
        int mx = -1;
        // int mn = arr[0];

        for (int i = 1; i < n; i++) {
            mx = max(mx, stalls[i]);
        }

        int e = mx;
        
        int mid = s +(e - s)/2;
        int ans = -1;
        
        while ( s <= e ){
            
            if( isPossible(stalls, n, k , mid) ){
                ans = mid;
                s = mid+1;
            }
            else{
                e = mid-1;
            }
            mid = s +(e - s)/2;
        }
        
        return ans;
    }
};