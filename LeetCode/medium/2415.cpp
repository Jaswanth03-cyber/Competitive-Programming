#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/
*/

class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<vector<int>> ans ;
        queue<TreeNode*> pq ;
        pq.push(root) ;

        int size = 0 ;
        vector<int> level ;

        while(!pq.empty()){
            size = pq.size() ;

            for(int i = 0 ; i < size ; i++){
                TreeNode* node = pq.front() ;
                pq.pop() ;
                level.push_back(node->val) ;
                if(node->left != nullptr){
                    pq.push(node->left) ;
                }
                if(node->right != nullptr){
                    pq.push(node->right) ;
                }
            }

            ans.push_back(level) ;
            level.clear() ;
        } 

        TreeNode *temp = root ;
        pq.push(temp) ;
        int index = 0 ;
        while(!pq.empty()){
            size = pq.size() ;
            if(index%2 == 1){
                reverse(ans[index].begin(), ans[index].end()) ;
            }
            for(int i = 0 ; i < size ; i++){
                TreeNode* node = pq.front() ;
                pq.pop() ;

                node->val = ans[index][i] ;
                if(node->left != nullptr){
                    pq.push(node->left) ;
                }
                if(node->right != nullptr){
                    pq.push(node->right) ;
                }
            }
            index++ ;
        } 
        return root ; 
    }
};