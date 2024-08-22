#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        
        for(long i= 1 ; i<=num ; i*=2){
            num = num^i;
        }
        return num;

        /*
        // Step 1: Find the number of bits in the binary representation of num
        int bitLength = 0;
        int temp = num;
        
        while (temp > 0) {
            bitLength++;
            temp >>= 1;  // Right shift temp to count the number of bits
        }

        // Step 2: Create a mask that has all bits set to 1 of the same length as num's binary representation
        int mask = (1 << bitLength) - 1;

        // Step 3: XOR the number with the mask to get the complement
        return num ^ mask;
        */
    }
};
