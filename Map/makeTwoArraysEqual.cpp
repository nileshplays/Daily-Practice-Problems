#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int, int> mp;

        //Inserting the elements of the 1st array into the map:
        for(int element : target){
            mp[element]++;
        }

        //Decrementing the elments of the map if that element is present in the 2nd array:
        for(int element : arr){
            if(mp[element] <= 0){
                return false;
            }
            mp[element]--;
        }
        
        return true;
    }
};