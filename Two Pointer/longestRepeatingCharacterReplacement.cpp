#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLength = 0;
        int l=0 , r =0;
        int n = s.length();
        unordered_map<char,int> mp;
        int maxFreq = 0;

        while(r < n){
            mp[s[r]]++;
            maxFreq = max(maxFreq, mp[s[r]]);
            int changes = (r-l+1) - maxFreq;

            while(changes > k){
                mp[s[l]]--;
                l++;

                maxFreq = 0;
                for (auto &p : mp) {
                    maxFreq = max(maxFreq, p.second);
                }
                changes = (r - l + 1) - maxFreq;
            }

            maxLength = max(maxLength , r-l+1);
            r++;

        }
        return maxLength;
    }
};