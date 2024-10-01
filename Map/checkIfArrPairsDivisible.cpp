#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {

        map<int,int> mp;

        for(int i =0 ; i < arr.size() ; i++){
            int rem = ((arr[i]%k)+k)%k;

            mp[rem]++; 
        }

        if(mp[0] %2 != 0){
            return false;
        }
        // for(auto i:mp){
        //     cout<<i.first<<" : ";
        //     cout<<i.second<<endl;
        // }
        for(int j = 1; j<=k/2 ;j++){
            int comp = k-j;

            if(mp[j] != mp[comp]){
                return false;
            }
        }
        return true;
    }
};