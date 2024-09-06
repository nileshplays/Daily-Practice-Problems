#include<bits/stdc++.h>
using namespace std;


 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,bool> mp;
        for(auto it : nums){
            mp[it] = 1;
        }

        while(mp.find(head->val) != mp.end()){
            head = head -> next;
        }

        if(head == NULL){
            return head;
        }
        // ListNode* temp = new ListNode();
        ListNode* curr = head->next;
        ListNode* prev = head;
        // int val = curr->data;

        // bool flag = false;

        while(curr != NULL){

            if(mp.find(curr->val) != mp.end()){
                prev->next = curr->next;
            }
            else{
                // flag = true;
                prev = curr;
            }
            
            curr = curr-> next;
        }
        return head;
    }
};