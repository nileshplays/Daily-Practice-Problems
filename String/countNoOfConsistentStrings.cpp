#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int> mp;
        for(int i=0; i<allowed.size() ;i++){
            mp[allowed[i]] = true;
        }

        int ans = 0;
        for(int i =0 ; i< words.size(); i++){

            bool flag = true;
            string temp = words[i];

            for(int j=0; j<temp.size();j++){
                if(mp.find(temp[j]) != mp.end())
                    continue;
                else{
                    flag = false;
                    break;
                }    

            }
            if(flag )   ans++;

        }
        return ans;
    }
};