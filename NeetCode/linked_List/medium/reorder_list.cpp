#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/reorder-list/
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
    void reorderList(ListNode* head) {
        vector<int> ans ;
        ListNode* node = head ;

        while(node != nullptr){
            ans.push_back(node->val) ;
            node= node->next ;
        }

        ListNode* temp = head ;
        int n = ans.size() ;
        int i = 0 ;
        while(temp != nullptr && temp->next != nullptr){
            temp->val = ans[i] ;
            temp->next->val = ans[n-i-1] ;
            i++ ;
            temp = temp->next->next ;
        }
        if(temp != nullptr){
            temp->val = ans[n/2]  ;
        }
    }
};