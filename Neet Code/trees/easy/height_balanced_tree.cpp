/*
https://leetcode.com/problems/balanced-binary-tree/
*/

#include<bits/stdc++.h>
using namespace std ;


 // Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/*
Travelling every node from top to bottom in a levl and in a levl from left to right and checking whether at a node both its left and right child are 
height balanced or not 
*/
class Solution {
public:
    int height(TreeNode *root){
        if(root == nullptr){
            return -1 ;
        }
        int height_of_node = max(height(root->left) +1, height(root->right) +1) ;

        return height_of_node ;
    }
    bool isBalanced(TreeNode* root) {

        bool ans = true ;
        if(root == nullptr){
            return ans ;
        }   

        queue<TreeNode*> pq ; 
        pq.push(root) ;

        while(!pq.empty()){
            int n = pq.size() ;
            for(int i = 0 ; i < n ; i++){
                TreeNode *curr = pq.front() ;
                pq.pop() ;

                int one = height(curr->left) ;
                int two = height(curr->right) ;

                if(abs(two - one) > 1){
                    ans = false ;
                    return ans ;
                }
                if(curr->left != nullptr){
                    pq.push(curr->left) ;
                }
                if(curr->right != nullptr){
                    pq.push(curr->right) ;
                }
            }
        }
        return ans ;
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    return 0 ;
}