#include<bits/stdc++.h>
using namespace std;

 //Definition for a binary tree node.
  struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
private:
    int ans = 0;

    vector<int> recurssion(TreeNode* root, int d){
        if(!root) return {};
        if(!root->left && !root->right)  return {1};

        vector<int> left = recurssion(root->left , d);
        vector<int> right = recurssion(root->right , d);
        vector<int> list;

        for(auto& a : left){
            for(auto& b : right){
                if(a+b <= d) ans++;
            }
            a++;
            if(a<d)  list.push_back(a);
        }
        for(auto& b : right){
            b++;
            if(b<d) list.push_back(b);
        }
        return list;
    }
public:

    int countPairs(TreeNode* root, int distance) {
        recurssion(root, distance);
        return ans;
    }
};