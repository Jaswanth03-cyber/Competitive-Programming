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
invert in the sense mirror image so going through every node of the tree ans swapping its left and right child 
swap is an inbuilt function which swaps both the variables given as parameter irrespective of the data type

Here we are going through every node of the tree in level order way from top to bottom and in a level from left to right 
*/

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        if(root == nullptr){
            return nullptr ;
        }  
        queue<TreeNode*> pq ;
        pq.push(root) ;

        while(!pq.empty()){

            TreeNode *current = pq.front() ;
            pq.pop() ;

            swap(current->left, current->right) ;

            if(current->left != nullptr){
                pq.push(current->left) ;
            }
            if(current->right != nullptr){
                pq.push(current->right) ;
            }
        } 
        return root ;   
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    return 0 ;
}