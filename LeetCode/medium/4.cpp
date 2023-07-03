#include<bits/stdc++.h>
using namespace std ;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> number(ListNode *l){
        ListNode* node = l ;
        vector<int> ans ;
        while(node != nullptr){
            ans.push_back(node->val) ;
            node = node->next ;
        } 
        reverse(ans.begin(), ans.end()) ;
        return ans ; 
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> ans1 = number(l1) ;
        vector<int> ans2 = number(l2) ;
        int size = 0 ;
        int n = ans1.size() ;
        int m = ans2.size() ;
        size = max(m, n) ;
        vector<int> ans(size, 0) ;
        int carry = 0 ; 
        int temp = 0 ;
        for(int i = size -1 ; i >=0 ; i--){
            temp = ans1[i] + ans2[i] ;
            if(temp >= 10){
                ans[i] = temp - 10 ;
                carry = 1 ;
            }
            else{
                ans[i] = temp ;
                carry = 0 ;
            }
        } 
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    return 0 ;
}