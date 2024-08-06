
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char , int> mp;
        priority_queue<int> pq;
        for(char str: word){
            mp[str]++;
        }

        for(auto& i: mp){
            pq.push(i.second);
        }

        int pushes =0 ;
        int size = pq.size();
        for(int i=0; i<size; ++i){
            int freq = pq.top();
            pq.pop();
            int val = freq*(i/8 +1);
            pushes += val;
        }
        return pushes;
    }
};