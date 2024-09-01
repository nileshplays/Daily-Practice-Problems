#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(string s1, string s2){
        bool color1 = (s1[0]-'a' + s1[1])%2;
        bool color2 = (s2[0]-'a' + s2[1])%2;
        
        if(color1 == color2)
            return 1;
        else{
            return 0;
        }
    }

    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        return check(coordinate1, coordinate2);
    }
};