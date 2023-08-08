#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
*/

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> bfs ;
        bfs.push(root) ;
        map<int, priority_queue<int, vector<int>, greater<int>>, greater<int>> mp ;

        int sum = 0 ; 
        int size = 0 ;
        int level = 1 ;
        while(!bfs.empty()){
            size = bfs.size() ;
            for(int i = 0 ; i < size ; i++){
                TreeNode* node = bfs.front() ;
                bfs.pop() ;
                sum = sum + node->val ;
                if(node->left != nullptr){
                    bfs.push(node->left) ;
                }
                if(node->right != nullptr){
                    bfs.push(node->right) ;
                }
            }
            if(mp.find(sum) != mp.end()){
                mp.find(sum)->second.push(level++) ;
            }
            else{
                priority_queue<int, vector<int>, greater<int>> pq ;
                pq.push(level++) ;
                mp.insert({sum, pq}) ;
            }
            sum = 0 ;
        }
        int ans = mp.begin()->second.top() ;
        return ans ;
    }
};