// LEETCODE 2

#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<stack>
#include<queue>
using namespace std;

/*
Definition for singly-linked list.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry = 0;
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;

        while(l1 != NULL || l2 != NULL){

            int sum = carry;

            if(l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }

            int digit = sum%10;
            carry = sum/10;

            ListNode *node = new ListNode(digit);
            temp->next = node;
            temp = temp->next;
        }

        if(carry > 0){

            ListNode *node = new ListNode(carry);
            temp->next = node;
            temp = temp->next;
        }

        return dummy->next;
    }
};