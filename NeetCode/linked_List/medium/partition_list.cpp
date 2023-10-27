#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/partition-list/
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
    ListNode* partition(ListNode* head, int x) {
        vector<int> vec1 ;
        vector<int> vec2 ;
        ListNode* temp = head ;
        while(temp != nullptr){
            if(temp->val < x){
                vec1.push_back(temp->val) ;
            }
            else if(temp->val >= x){
                vec2.push_back(temp->val) ;
            }
            temp = temp->next ;
        }
        int n = vec1.size() ;
        int i = 0 ;
        ListNode* node = head ;
        while(i < n){
            node->val = vec1[i++] ;
            node = node->next ;
        }
        i = 0 ;
        while(node != nullptr){
            node->val = vec2[i++] ;
            node = node->next ;
        }
        return head;
    }
};