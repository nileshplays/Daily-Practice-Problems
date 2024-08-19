#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int,string> mp{{1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},{90,"XC"},{50,"L"},{40,"XL"},{10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"}};
        string ans ="";

        vector<int> val = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9 ,5 ,4, 1};

        for(int values : val){

            while(num >= values){
                ans += mp[values];
                num = num - values;
            }
        }
        return ans;
    }
};