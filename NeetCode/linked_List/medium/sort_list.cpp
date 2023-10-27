#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/sort-list/
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
    ListNode* sortList(ListNode* head) {
        vector<int> vec ;
        ListNode* temp = head ;

        while(temp != nullptr){
            vec.push_back(temp->val) ;
            temp = temp->next ;
        }
        sort(vec.begin(), vec.end()) ;
        ListNode* ans = head ;
        int i = 0 ;
        int n = vec.size() ;
        while(ans != nullptr){
            ans->val = vec[i] ;
            ans = ans->next ;
            i++ ; 
        }
        return head ; 
    }
};