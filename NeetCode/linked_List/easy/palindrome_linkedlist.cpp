#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/palindrome-linked-list/
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
    bool isPalindrome(ListNode* head) {
        vector<ListNode*> arr ;

        while(head != nullptr){
            arr.push_back(head) ;
            head = head->next ;
        }
        if((arr.size() == 0) || (arr.size() == 1)){
            return true ;
        }
        int n = arr.size() ;
        for(int i = 0 ; i < n/2 ; i++){
            if(arr[i]->val != arr[n - i - 1]->val){
                return false ;
            }
        }
        return true ;
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    return 0 ;
}