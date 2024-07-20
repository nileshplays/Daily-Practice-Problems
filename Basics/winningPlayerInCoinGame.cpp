#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string losingPlayer(int x, int y) {
        int round = min(x, y/4);
        if(round % 2 ==0){
            return "Bob";
        }
        else{
            return "Alice";
        }
    }
};