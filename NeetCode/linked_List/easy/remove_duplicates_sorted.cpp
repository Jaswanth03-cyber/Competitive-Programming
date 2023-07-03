#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/remove-duplicates-from-sorted-list/
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* 
checking by value at start took the value of head so checked if there are any further nodes with value equal to that of head 
if not there then we update the new value of the variable which is the next node value, we check if there is any node of this value 
as this is a sorted linked list it will be easy final node is not checked as in the while loop we had a condition curr->next != nullptr so final node
is not checked so added a if condition for that after the loop
*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr){
            return head ;
        }      
        if(head->next == nullptr){
            return head ;
        }
        int value = head->val ;
        ListNode *curr = head ;
        ListNode *result = head ;
        while(curr->next != nullptr){
            if(curr->next->val == value){
                ListNode *p = curr->next ;
                curr->next = curr->next->next ;
                delete p ;
            }
            else{
                curr = curr->next ;
                value = curr->val ;
            }
        }
        if(curr->val == value){
            curr = nullptr ;
        }
        return result ;
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    ListNode *one = new ListNode(1) ;
    ListNode *two = new ListNode(1) ;
    ListNode *three = new ListNode(2) ;

    one->next = two ;
    two->next = three ;
    Solution ans ;
    ListNode* node = ans.deleteDuplicates(one) ;

    while(node != nullptr){
        cout<<node->val<<" " ;
        node = node->next ;
    }
    cout<<endl ;
    return 0 ;
}