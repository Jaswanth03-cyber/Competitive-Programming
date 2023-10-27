#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/rotate-list/description/
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
    ListNode* rotateRight(ListNode* head, int k) {
        vector<int> ans ;
        ListNode* node = head ;
        ListNode* temp = head ;
        while(temp != nullptr){
            ans.push_back(temp->val) ;
            temp = temp->next ;
        }
        int count = ans.size() ;
        vector<int> vec(count, 0) ;
        for(int i = 0 ; i < count ; i++){
            vec[(i+k)%count] = ans[i] ;
        }
        int i = 0 ;
        while(node != nullptr){
            node->val = vec[i] ;
            i++ ;
            node = node->next ;
        }
        return head ;
    }
};