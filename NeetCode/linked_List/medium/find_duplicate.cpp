#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/find-the-duplicate-number/
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
    int findDuplicate(vector<int>& nums) {
        int ans = 0 ;
        sort(nums.begin(), nums.end()) ;
        int n = nums.size() ;
        for(int i = 0 ; i < n -1 ; i++){
            if(nums[i] == nums[i+1]){
                ans = nums[i] ;
            }
        }
        return ans ; 
    }
};

/*
we can find it by using finding cycle like in the linked list
*/