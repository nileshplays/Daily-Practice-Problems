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
public:

    void preOrder(TreeNode* root ,string s, vector<string> &num){

        if(root== NULL){
            return;
        }
        
        int x = root->val;
        s = s+ to_string(x);
        // cout<<"String: "<<s<<"! :"<<endl;
        if(root->left ==NULL && root->right == NULL){
            num.push_back(s);
            // cout<<"Val: "<<root->val<<endl;
            return;
        }
        else{
            // cout<<"StringELSE: "<<s<<endl;
            preOrder(root->left , s , num);
            // cout<<"StringL: "<<s<<endl;
            preOrder(root->right,s , num);
            // cout<<"StringR: "<<s<<endl;
        }

    }


    int sumNumbers(TreeNode* root) {
        vector<string> num;
        preOrder(root, "" ,num);

        int sum = 0;
        for(int i=0; i <num.size() ;i++){
            int y = stoi(num[i]);
            sum += y;
        }

        return sum;
    }
};