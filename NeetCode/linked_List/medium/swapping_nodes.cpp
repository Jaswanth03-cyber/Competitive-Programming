#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> vec = {0} ;
        ListNode* temp = head ;
        int count = 1 ;
        while(temp != nullptr){
            vec.push_back(temp->val) ;
            temp = temp->next ;
            count++ ;
        }  
        swap(vec[k], vec[count-k]) ;
        ListNode* node = head ;
        int i = 1 ;
        while(node != nullptr){
            node->val = vec[i++] ;
            node = node->next ;
        } 
        return head ;
    }
};