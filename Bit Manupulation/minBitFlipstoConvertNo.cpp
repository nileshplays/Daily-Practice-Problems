#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x = start ^ goal;

        int count = 0;
        while(x > 0){
            if(x%2 == 1)    count++;
            x = x/2;
        }

        return count;
    }
};