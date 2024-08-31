#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string padding(int &num){

        string str = to_string(num);
        while(str.length() < 4){
            str = '0' + str;
        }

        return str;
    }

    int generateKey(int num1, int num2, int num3) {
        
        string str1 = padding(num1);
        string str2 = padding(num2);
        string str3 =padding(num3);

        string ans ="";

        for(int i=0 ; i< 4 ;i++){
            ans += min({str1[i],str2[i],str3[i]});
        }

        int res = stoi(ans);

        return res;
    }
};