#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/remove-linked-list-elements/
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr){
            return nullptr ;
        }
        if(head->next == nullptr){
            if(head->val == val){
                return nullptr ;
            }
            else{
                return head ;
            }
        }
        ListNode *result = head ;
        ListNode *curr = head ;
        while(curr->next != nullptr){
            if(curr->next->val == val){
                ListNode *p = curr->next ;
                curr->next = curr->next->next ;
                delete p ;
            }
            else{
                curr = curr->next ;
            }
        } 
        // this is beacuse here in the loop we did not check first node directly started from second one 
        if(result->val == val){
            result = result->next ;
        }
        return result ;    
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    ListNode *one = new ListNode(6) ;
    ListNode *two = new ListNode(2) ;
    ListNode *three = new ListNode(3) ;
    ListNode *four = new ListNode(4) ;
    ListNode *five = new ListNode(6) ;
    ListNode *six = new ListNode(5) ;
    ListNode *seven = new ListNode(6) ;

    one->next = two ;
    two->next = three ;
    three->next = four ;
    four->next = five ;
    five->next = six ;
    six->next = seven ;

    Solution ans ;
    ListNode *curr = ans.removeElements(one,6) ;

    while(curr != nullptr){
        cout<<curr->val<<" " ;
        curr = curr->next ;
    }
    cout<<endl ;
    return 0 ;
}