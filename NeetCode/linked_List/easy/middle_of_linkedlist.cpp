#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/middle-of-the-linked-list/
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
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> arr ;
        while(head != nullptr){
            arr.push_back(head) ;
            head = head->next ;
        }
        
        int middle = arr.size()/2  ;
        return arr[middle] ;
    }
};