#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/
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
    int pairSum(ListNode* head) {
        vector<int> vec ;
        ListNode* temp = head;
        while(temp != nullptr){
            vec.push_back(temp->val) ;
            temp = temp->next ;
        }

        int n = vec.size() ;
        int ans = 0 ;
        for(int i = 0 ; i <= n/2 -1 ; i++){
            ans = max(ans, vec[i]+vec[n-i-1]) ;
        }
        return ans ; 
    }
};