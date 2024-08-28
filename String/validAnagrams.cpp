#include<bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())    
            return false;
        unordered_map<int,int> mp;
        for(int i=0; i<t.size(); i++){
            mp[t[i]-'a']++;
        }

        for(int j=0 ;j < s.size(); j++){
            if(mp[s[j]-'a'] !=0){
                mp[s[j]-'a']--;
            }
        }
        
        for(auto i: mp){
            if(i.second != 0)
                return false;
        }
        return true;
    }
};