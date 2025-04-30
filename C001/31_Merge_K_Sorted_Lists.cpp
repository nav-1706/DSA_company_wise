// LEETCODE 23

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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* merge(ListNode* list1, ListNode* list2) {
        
        ListNode* tempA = list1;
        ListNode* tempB = list2;

        ListNode* dummy = new ListNode(-1);
        ListNode* tempC = dummy;

        while(tempA!=NULL && tempB!=NULL){

            if(tempA->val <= tempB->val){
                tempC->next = tempA;
                tempC = tempC->next;
                tempA = tempA->next;
            }

            else{
                tempC->next = tempB;
                tempC = tempC->next;
                tempB = tempB->next;
            }
        }

        if(tempA == NULL){
            tempC->next = tempB;
        }

        else{
            tempC->next = tempA;
        }

        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.size() == 0) return NULL;
        if(lists.size() == 1) return lists[0];
        
        while(lists.size() > 1){

            auto list1 = lists[lists.size()-1];
            lists.pop_back();
            auto list2 = lists[lists.size()-1];
            lists.pop_back();

            lists.push_back(merge(list1, list2));
        }

        return lists[0];
    }
};