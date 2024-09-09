#include<bits/stdc++.h>
using namespace std;


//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        ListNode* temp = head;

        vector<vector<int>> mat(m,vector<int>(n,-1));

        int startRow = 0, endRow = m-1, startCol = 0, endCol= n-1;

        while(temp!=NULL){
            for(int col =startCol; col<= endCol ;col++){ 
                if(temp ==NULL)  break;
                mat[startRow][col] = temp->val;
                temp = temp->next;
            }
            startRow++;

            for(int row =startRow; row <=endRow ;row++){ 
                if(temp ==NULL)  break;
                mat[row][endCol] = temp->val;
                temp = temp->next;
            }
            endCol--;

            for(int col = endCol; col >= startCol ;col){
                if(temp==NULL)  break;
                mat[endRow][col] = temp->val;
                temp = temp->next;
            }
            endRow--;

            for(int row = endRow; row>= startRow; row--){
                if(temp==NULL)  break;
                mat[row][startCol] = temp->val;
                temp = temp->next;
            }
            startCol++;
        }

        return mat;
    }
};