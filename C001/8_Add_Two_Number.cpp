// LEETCODE - 2

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

        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        while(l1 != NULL && l2 != NULL){

            int sum = l1->val + l2->val + carry;
            carry = sum/10;

            ListNode* node = new ListNode(sum%10);
            curr->next = node;
            curr = curr->next;

            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1 != NULL){

            int sum = l1->val + carry;
            carry = sum/10;

            ListNode* node = new ListNode(sum%10);
            curr->next = node;
            curr = curr->next;

            l1 = l1->next;
        }

        while(l2 != NULL){

            int sum = l2->val + carry;
            carry = sum/10;

            ListNode* node = new ListNode(sum%10);
            curr->next = node;
            curr = curr->next;
            
            l2 = l2->next;
        }

        if(carry > 0){
            ListNode* node = new ListNode(carry);
            curr->next = node;
        }

        return (dummy->next);
    }
};