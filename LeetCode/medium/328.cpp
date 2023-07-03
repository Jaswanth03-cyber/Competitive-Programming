/*

328. Odd Even Linked List
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

https://leetcode.com/problems/odd-even-linked-list/

*/

#include<bits/stdc++.h>
using namespace std ;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


/*

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

 My Solution 

class Solution{
public:
    ListNode* oddEvenList(ListNode* head){

        ListNode* odd ;
        ListNode* even ;
        ListNode* ans ;
        ListNode* first_even ;
        int i = 1 ;
        odd = head ;
        head = head->next ;
        ans = odd ;
        i++ ;

        if(head != nullptr){
            even = head ;
            first_even = even ;
            head = head->next ;
            i++ ;
        }
        else{
            return ans ;
        }
        while(head != nullptr){
            if(i%2 == 1){
                odd->next = head ;
                head = head->next ;
                odd = odd->next ;
            }
            else{
                even->next = head ;
                head = head->next ;
                even = even->next ;
            }
            i++ ;
        }
        odd->next = first_even ;
        return ans ;
    }
};
*/
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr)
            return nullptr ;
        ListNode* odd  = head;
        ListNode* even = head -> next;
        ListNode* evenhead = head -> next;
        
        while(even != nullptr and even -> next != nullptr){
            // put odd to the odd list
            odd ->next = odd -> next -> next;
            // Move the pointer to the next odd
            odd = odd -> next;
        
            // put even to the even list
            even -> next = even -> next -> next;
            // Move the pointer to the next even
            even = even -> next;
        }
        odd -> next = evenhead;
        return head;    
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;


    return 0 ;
}