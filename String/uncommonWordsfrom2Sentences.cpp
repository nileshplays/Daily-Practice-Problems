#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {

        string s = s1 +" "+ s2;
        vector<string> allWords;
        vector<string> ans;
        string word="";
        for(int i = 0; i< s.size();i++){
            int ch = s[i];
            if(ch== ' '){
                if(!word.empty()){
                    allWords.push_back(word);
                    word ="";
                }
            }
            else{
                word +=ch;
            }
            if(i == s.size()-1){
                allWords.push_back(word);
            }
        }

        for(auto it: allWords){
            cout<<it<<endl;
        }

        unordered_map<string,int> mp;

        for(string s : allWords){
            mp[s]++;
        }

        for(auto it : mp){
            // cout<<"First: "<<it.first<<endl;
            // cout<<"Second: "<<it.second<<endl;
            if(it.second == 1){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};