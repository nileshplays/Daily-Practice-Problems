#include<bits/stdc++.h>
using namespace std;

// Optimized to O(n)
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxLength =0;
        int n = fruits.size();
        unordered_map<int,int> mp;
        int r =0 ,l =0;
        while(r < n){

            mp[fruits[r]]++;
        
            if(mp.size() > 2){
                mp[fruits[l]]--;
                if (mp[fruits[l]] == 0) {
                    mp.erase(fruits[l]);
                }
                l++;
            }

            maxLength = max(maxLength , r-l+1);
            r++;
        }

        return maxLength;
    }
};

// Sliding Window Approach     T.C :: O(n)  ,  S.C. :: O(n)
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxLength =0;
        int n = fruits.size();
        unordered_map<int,int> mp;
        int r =0 ,l =0;
        while(r < n){

            mp[fruits[r]]++;
        
            while(mp.size() > 2){
                mp[fruits[l]]--;
                if (mp[fruits[l]] == 0) {
                    mp.erase(fruits[l]);
                }
                l++;
            }

            maxLength = max(maxLength , r-l+1);
            r++;
        }

        return maxLength;
    }
};


// Naive Approach                 T.C. : O(n^2) , S.C. : O(n)
/*
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxLength = 0;
        for(int i=0; i< fruits.size(); i++){
            set<int> st;

            for(int j= i; j<fruits.size();j++){
                st.insert(fruits[j]);

                if(st.size()<=2){
                    int length = j-i+1;
                    maxLength= max(maxLength,length);
                }
                else{
                    break;
                }

            }
        }
        return maxLength;
    }
};
*/