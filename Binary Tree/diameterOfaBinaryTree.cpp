#include<bits/stdc++.h>
using namespace std;


//  Definition for a binary tree node.
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
    int height(TreeNode* root ){

        if(root == NULL)    
            return 0;
        
        int left = height(root->left);
        int right = height(root->right);
        int count = max(left, right) +1;
        return count;
    }
*/
    pair<int,int > diameterFast(TreeNode* root){
        if(root == NULL){
            pair<int,int> p = make_pair(0,0);
            return p;
        }

        pair<int,int> left = diameterFast(root->left);
        pair<int,int> right = diameterFast(root->right);

        int way1 = left.first;
        int way2 = right.first;
        int way3 = left.second + right.second ;

        pair<int ,int> ans;
        ans.first = max(way1, max(way2,way3));
        ans.second = max(left.second , right.second) +1;
        return ans;

    }

    int diameterOfBinaryTree(TreeNode* root) {
        

        return diameterFast(root).first;
        /*
            int way1 = diameterOfBinaryTree(root->left);
            int way2 = diameterOfBinaryTree(root->right);
            // int way3 = height(root->left)+ height(root->right) ;

            int ans = max(way1 , max(way2, way3));

            return ans;
        */
    }
};