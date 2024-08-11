#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int sum = INT_MIN;
        int n = energy.size();
        
        for (int i = 0; i < k; ++i) {
            int currSum = 0;

            for (int j = energy.size() - 1 - i; j >= 0; j -= k) {
                currSum += energy[j];
                sum = max(sum, currSum);
            }
        }
    
        return sum;
    }
};