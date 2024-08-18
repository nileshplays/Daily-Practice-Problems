#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";

        for(int i=0; i<strs[0].size(); i++){
            char ch = strs[0][i];
            bool match = true;

            // compare thaht char with other string same element
            for(int j=0 ; j<strs.size() ;j++){
                if(strs[j].size()<i || ch !=strs[j][i]){
                    match = false;
                    break;
                }
            }
            if(match == false)
                break;
            else{
                ans.push_back(ch);
            }

        }
        return ans;
    }
};