#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSeniors(vector<string>& details) {

        int count = 0;

        for (const string& detail : details) {

            char ageTensChar = detail[11];
            char ageOnesChar = detail[12];

            int ageTens = ageTensChar - '0';
            int ageOnes = ageOnesChar - '0';
            int age = ageTens * 10 + ageOnes;

            if (age > 60) {
                count++;
            }
        }
        return count;
    }
};