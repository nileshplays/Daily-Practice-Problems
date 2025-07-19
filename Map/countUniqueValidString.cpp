#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int vowelCount(string& s) {
        unordered_map<char,int> mp;
        
        for(char c : s) {
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                mp[c]++;
            }
        }

        if(mp.empty()) return 0;

        int count = mp.size(), multiple = 1;
        for(auto it : mp){
            multiple *= it.second;
        }

        int ans = 1;
        for(int i = 2; i <= count; i++){
            ans *= i;
        }

        return ans * multiple;
    }
};