#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        map<char,int> mp;
        int count = 0;
        for(int i=0; i<s.size() ;i++){
            mp[s[i]]++;
            if(mp[s[i]] > 2){
                count +=2;
                mp[s[i]] = mp[s[i]] -2;
            }
        }
        
        int result = s.size() - count;
        return result;
    }
};