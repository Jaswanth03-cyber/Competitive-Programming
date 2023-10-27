#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/swap-nodes-in-pairs/
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
    ListNode* swapPairs(ListNode* head) {
        vector<int> vec ;
        ListNode* temp = head ;

        while(temp != nullptr){
            vec.push_back(temp->val) ;
            temp = temp->next ;
        }
        temp = head ;
        int i = 0 ;
        while(temp != nullptr && temp->next != nullptr){
            temp->val = vec[i+1] ;
            temp->next->val = vec[i] ;
            i = i + 2 ;
            temp = temp->next->next ;
        }
        return head ; 
    }
};