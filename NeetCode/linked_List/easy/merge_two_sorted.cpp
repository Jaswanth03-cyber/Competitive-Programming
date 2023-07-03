#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/merge-two-sorted-lists/
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(list1 == nullptr){
            return list2 ;
        }
        if(list2 == nullptr){
            return list1 ;
        }
        ListNode *curr ;
        if(list1->val <= list2->val){
            curr = list1 ;
            list1 = list1->next ;
        }
        else{
            curr = list2 ;
            list2 = list2->next ;
        }
        ListNode *result = curr ;
        while((list1 != nullptr) && (list2 != nullptr)){
            if(list1->val <= list2->val){
                curr->next = list1 ;
                list1 = list1->next ;
            }
            else{
                curr->next = list2 ;
                list2 = list2->next ;
            }
            curr = curr->next ;
        }
        if(list1 == nullptr){
            while(list2 != nullptr){
                curr->next = list2 ;
                list2 = list2->next ;
                curr = curr->next ;
            }
        }
        if(list2 == nullptr){
            while(list1 != nullptr){
                curr->next = list1 ;
                list1 = list1->next ;
                curr = curr->next ;
            }
        }
        curr->next = nullptr ;
        return result ; 
    }
};



int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    return 0 ;
}