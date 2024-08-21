#include<bits/stdc++.h>
using namespace std;

// OPTIMAL CODE ::     T.C = O(n)     ,    S = O(256)
/*
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(255,-1);
        int n =s.size();
        int l =0 , r=0;

        int maxLength = 0;
        while(r  < n){
            if(hash[s[r]] != -1){
                if(hash[s[r]] >= l){
                    l = hash[s[r]] +1;
                }
            }
            int length = r-l+1;
            maxLength = max(length, maxLength);
            hash[s[r]] = r;
            r++;
        }
        
        return maxLength;
    }
};
*/


class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {

        int i=0 ,j =0;
        while(i<nums1.size() && j < nums2.size()){
            if(nums1[i] == nums2[j]){
                return nums1[i];
            }
            else if(nums1[i] <nums2[j]){
                i++;
            }
            else{
                j++;
            }

        }

        return -1;
    }
};

