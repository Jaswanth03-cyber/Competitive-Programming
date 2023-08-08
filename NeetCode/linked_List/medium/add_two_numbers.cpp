#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/add-two-numbers/
*/

class Solution {
public:
    vector<int> number(ListNode *node){
        vector<int> ans ;
        while(node != nullptr){
            ans.push_back(node->val) ;
            node = node->next ;
        }
        return ans ;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1 ;
        ListNode* temp2 = l2 ;
        vector<int> num1 = number(temp1) ;
        vector<int> num2 = number(temp2) ;
        int size1 = num1.size() ;
        int size2 = num2.size() ;
        int size = max(size1, size2) ;
        num1.resize(size+1) ;
        num2.resize(size+1) ;
        int carry = 0 ;
        int sum = 0 ;
        vector<int> ans(size+1, 10) ;
        for(int i = 0 ; i < size ; i++){
            sum = (num1[i] + num2[i] + carry)%10 ;
            carry = (num1[i] + num2[i] + carry)/10 ;
            ans[i] = sum ;
        }
        if(carry > 0){
            ans[size] = carry ;
        }

        ListNode* final = new ListNode(ans[0]) ;
        ListNode *dummy = final ;
        for(int i = 1 ; i <= size ; i++){
            if(ans[i] != 10){
                final->next = new ListNode(ans[i]) ;
                final = final->next ;
            }
            else{
                break ;
            }
        }
        return dummy ;
    }
};