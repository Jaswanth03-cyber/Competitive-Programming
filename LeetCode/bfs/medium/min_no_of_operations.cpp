#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/
*/
class Solution {
public:
    int minops(vector<int> &arr){
        int n = arr.size() ;
        vector<int> temp = arr ;
        sort(temp.begin(), temp.end()) ;
        unordered_map<int, int> mp ;
        for(int i = 0 ; i < n ; i++){
            mp[temp[i]] = i ;
        }
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(arr[i] != temp[i]){
                int index = mp[arr[i]] ;
                swap(arr[index], arr[i]) ;
                ans++ ;
                i-- ; 
            }
        }
        return ans ;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> pq ;
        pq.push(root) ;
        int size = 0 ;
        int ans = 0 ;
        while(!pq.empty()){
            size = pq.size() ;
            vector<int> temp ;
            for(int i = 0 ; i < size ; i++){
                TreeNode* node = pq.front() ;
                pq.pop() ;
                temp.push_back(node->val) ;
                if(node->left != nullptr){
                    pq.push(node->left) ;
                }
                if(node->right != nullptr){
                    pq.push(node->right) ;
                }
            }
            ans += minops(temp) ;
        } 
        return ans ;
    }
};

/*
once swapped it does not mean we have the right value at that position so thats why we decrement the i whenever arr[i] != temp[i] 
we check this until we get the right value at position i one we get the right value at position i, then there is no need to decrement i
and also we go further this is the process from which we get the min no of swaps to get a sorted array(increasing) 

when given sorted consider decreasing also if did not mention increasing
*/