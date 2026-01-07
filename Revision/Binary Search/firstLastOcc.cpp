#include<bits/stdc++.h>
using namespace std;

int firstOcc(vector<int>& arr, int n, int k){
    int s = 0, e =n-1;
    int m = s+ (e-s)/2;
    int first =-1;
    while(s < e){
        if(arr[m] == k){
            first = m;
            e = m-1;
        }
        else if( arr[m] < k ){
            s = m+1;
        }
        else{
            e = m-1;
        }

        m = s+(e-s)/2;
    }
    return first;
}