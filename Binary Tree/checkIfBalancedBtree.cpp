#include<bits/stdc++.h>
using namespace std;


 // Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
/*
    int height(TreeNode* root){
        if(root == NULL)
            return 0;
        
        int left = height(root->left);
        int right = height(root->right);
        int count = max(left, right) +1;

        return count;
    }
*/
    pair<bool , int> balancedOptim(TreeNode* root){
        if(root ==NULL){
            pair<bool, int> p = make_pair(true , 0);
            return p;
        }

        pair<bool, int> ans;

        pair<bool,int> left = balancedOptim(root->left);
        pair<bool,int> right = balancedOptim(root->right);

        // int ansLeft = left.first;
        // int ansRight = right.first;
        int diff = abs(left.second - right.second) <=1;

        ans.second = max(left.second ,right.second) +1;
        

        if(left.first && right.first && diff){
            ans.first = true;
        }
        else{
            ans.first = false;
        }
        return ans;
    }

    bool isBalanced(TreeNode* root) {
        
        return balancedOptim(root).first;


        /*
        if(root == NULL)
            return true;

        int left = isBalanced(root->left);
        int right = isBalanced(root->right);

        int diff = abs(height(root->left) - height(root->right)) <=1;

        return left && right && diff;
        */
    }
};