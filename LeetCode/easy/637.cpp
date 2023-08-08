#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/average-of-levels-in-binary-tree/
*/
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans ;
        queue<TreeNode*> pq ;
        pq.push(root) ;
        int size = 0 ;
        double avg = 0.000 ;
        double sum = 0 ;
        while(!pq.empty()){
            size = pq.size() ;
            for(int i = 0 ; i < size ; i++){
                TreeNode *temp = pq.front() ;
                pq.pop() ;
                sum = sum + temp->val ;
                if(temp->left != nullptr){
                    pq.push(temp->left) ;
                }
                if(temp->right != nullptr){
                    pq.push(temp->right) ;
                }
            }
            avg = sum/size ;
            ans.push_back(avg) ;
            sum = 0 ;
        }  
        return ans ; 
    }
};