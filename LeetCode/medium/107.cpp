#include <bits/stdc++.h>
using namespace std ;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/*
https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
*/
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> temp ;
        if(root == nullptr){
            return temp ;
        } 
        queue<TreeNode*> pq ;
        pq.push(root) ;

        int size = 0 ;
        vector<int> level ;
        while(!pq.empty()){
            size = pq.size() ;
            level.clear() ;
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
            temp.push_back(level) ;
        }

        vector<vector<int>> ans ;
        size = temp.size() ;
        for(int i = size -1 ; i >= 0 ; i--){
            ans.push_back(temp[i]) ;
        }
        return ans ; 
    }
};

