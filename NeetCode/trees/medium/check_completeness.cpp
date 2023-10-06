#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/check-completeness-of-a-binary-tree/
*/
/*
Assume this graph as a heap so heap is of like ordering of the indices in an array if in case anywhere heap indexing did not work then return false
so if we know the index of the parent as i then both the child will be 2*i+1, 2*i+2 
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> pq ;  
        pq.push({root, 0}) ;
        int curr = 0 ;
        while(!pq.empty()){
            int size = pq.size() ;
            for(int i = 0 ; i < size ; i++){
                TreeNode* node = pq.front().first ;
                int top = pq.front().second ;
                pq.pop() ;
                if(curr != top){
                    return false ;
                }
                curr++ ;
                if(node->left != nullptr){
                    pq.push({node->left, 2*top+1}) ;
                }
                if(node->right != nullptr){
                    pq.push({node->right, 2*top+1}) ;
                }
            }
        }
        return true ;
    }
};