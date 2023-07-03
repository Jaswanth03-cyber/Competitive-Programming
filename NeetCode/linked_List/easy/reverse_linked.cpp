#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/reverse-linked-list/
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
    ListNode* reverseList(ListNode* head){

        if(head->next == nullptr){
            return head ;
        }
        stack<ListNode*> st ;
        ListNode *curr = head ;
        while(curr->next != nullptr){
            st.push(curr) ;
            curr = curr->next ;
        }
        ListNode *tail = curr ;
        while(!st.empty()){
            tail->next = st.top() ;
            st.pop() ;
            tail = tail->next ;
        }
        tail->next = nullptr ;
        return curr ;
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    ListNode *node = new ListNode(1) ;
    node->val = 1 ;
    ListNode *one = new ListNode(2) ;
    ListNode *two = new ListNode(3) ;
    ListNode *three = new ListNode(4) ;
    ListNode *four = new ListNode(5) ;

    node->next = one ;
    one->next = two ;
    two->next = three ;
    three->next = four ;

    Solution ans ;
    ListNode *curr = ans.reverseList(node) ;

    while(curr != nullptr){
        cout<<curr->val<<" " ;
        curr = curr->next ;
    }
    cout<<endl ;

    return 0 ;
}