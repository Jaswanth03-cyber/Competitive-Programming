#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/maximum-width-of-binary-tree/
*/

/*
to avoid integer overflow we are removing the value of the left most node of the level this does not effect the difference.  
*/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> pq ;
        pq.push({root, 0}) ;

        int size = 0 ;
        long long index = 0 ;
        long long start = 0 ;
        long long end = 0 ;
        long long ans = 0 ;
        while(!pq.empty()){
            size = pq.size() ;
            long long temp = pq.front().second ;
            for(int i = 0 ; i < size ; i++){
                TreeNode* node = pq.front().first ;
                index = pq.front().second - temp ;
                pq.pop() ;
                if(i == 0){
                    start = index ;
                }
                if(i == size -1){
                    end = index ;
                }
                if(node->left != nullptr){
                    pq.push({node->left, 2*index+1}) ;
                }
                if(node->right != nullptr){
                    pq.push({node->right, 2*index+2}) ;
                }
            }
            cout<<endl ;
            ans = max(ans, end-start+1) ;
        } 
        int res = ans ;
        return res ; 
    }
};