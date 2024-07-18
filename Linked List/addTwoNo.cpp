#include<bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* add(ListNode* first, ListNode* second){
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;
        int carry =0;
        while(first!=NULL || second !=NULL || carry!=0){
            int val1 =0;
            int val2 =0;
            if(first!=NULL)
                val1 = first->val;
            if(second!=NULL)
                val2 = second->val;

            int sum = val1 + val2 + carry;
            int digit = sum% 10;
            carry = sum/10;
            ListNode* temp = new ListNode(digit);
            if(ansHead == NULL){
                ansHead = temp;
                ansTail = temp;
            }
            else if(ansHead !=NULL){
                ansTail->next = temp;
                ansTail = temp;
            }
            if(first!=NULL){
                first = first->next;
            }
            if(second !=NULL)
                second= second->next;
        }
        return ansHead;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1, l2);
    }
};