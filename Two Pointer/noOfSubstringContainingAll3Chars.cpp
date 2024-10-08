#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        vector<int> lastSeen(3,-1);

        for(int i=0; i< s.length(); i++){
            // vector<int> freq(3,0);
                lastSeen[s[i]-'a'] = i;
                if(lastSeen[0] != -1 &&lastSeen[1] != -1 &&lastSeen[2] != -1)
                    count = count+1+ min({lastSeen[0],lastSeen[1],lastSeen[2]});
            
        }
        return count;
    }
};