#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/even-odd-tree/description/
*/

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> pq ;
        pq.push(root) ; 
        int size = 0 ;
        int level = 0 ;

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
            size = temp.size() ;
            if(level%2 == 0){
                if(temp[0]%2 == 0){
                    return false ;
                }
                for(int i = 1 ; i < size ; i++){
                    if(temp[i-1] >= temp[i] || temp[i]%2 == 0){
                        return false ;
                    }
                }
            }
            else{
                if(temp[0]%2 == 1){
                    return false ;
                }
                for(int i = 1 ; i < size ; i++){
                    if(temp[i-1] <= temp[i] || temp[i]%2 == 1){
                        return false ;
                    }
                }
            }
            level++ ;
        }  
        return true ;    
    }
};