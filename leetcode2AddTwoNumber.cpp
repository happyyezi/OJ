//
// Created by Alina on 16/7/9.
//
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode * next = NULL;
    ListNode(int v):val(v),next(NULL){}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL || l2 == NULL)
            return NULL;
        int carry = 0;
        ListNode * head = NULL;
        if(l1 != NULL && l2 != NULL){
            head = new ListNode((l1->val + l2->val)%10);
            if (l1->val + l2->val > 9)
                carry = 1;
        }
        ListNode * tail = head;
        while(l1->next != NULL && l2->next != NULL){
            int sum = l1->next->val + l2->next->val + carry;
            if (sum > 9)
                carry = 1;
            else
                carry = 0;
            tail->next = new ListNode(sum%10);
            tail = tail -> next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1->next != NULL){
            tail->next = new ListNode((l1->next->val + carry)%10);
            if(l1->next->val + carry > 9)
                carry = 1;
            else
                carry = 0;
            tail = tail->next;
            l1 = l1->next;

        }
        while(l2 -> next != NULL){
            tail->next = new ListNode((l2->next->val + carry)%10);
            if (l2->next->val + carry > 9)
                carry = 1;
            else
                carry = 0;
            tail = tail->next;
            l2 = l2->next;
        }
        if(carry > 0)
            tail->next = new ListNode(carry);
        return head;
    }
};

//int main(){
//    ListNode* l1 = new ListNode(0);
////    l1->next = new ListNode(4);
////    l1->next->next = new ListNode(3);
//    ListNode * l2 = new ListNode(7);
//    l2->next = new ListNode(3);
////    l2->next->next = new ListNode(4);
//    Solution s;
//    ListNode * result = s.addTwoNumbers(l1,l2);
//    while(result != NULL) {
//        cout << result->val << "->";
//        result = result->next;
//    }
//    cout<<endl;
//    cout << "end"<<endl;
//    return 0;
//}