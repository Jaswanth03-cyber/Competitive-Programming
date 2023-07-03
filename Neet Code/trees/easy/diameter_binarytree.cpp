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
diameter in the sense longest possible path 
initially I have thought that longest path always passes through the root so just calculated roots left child and right child height and added 
both of them and also added 2 to it but its wrong 

there is no rule that longest path should always pass through the diameter 
So traversing every node and calculating maximum length of the path passing through that node and taking the maximum of all

So traversing every node level wise to traverse every node level wise we know how to do it we need a queue push root and its left and right nodes
to the queue first left and then right as level order we are by default taking it from top and in a level from left to right 
*/

/*
height of the tree recursively calculates it watches both the left and right children as height is maximum height from leaf to the node 
height of leaf is considered to be 0 so if nullptr returning 1 
*/
class Solution {
public:
    int heightoftree(TreeNode *root){
        if(root == nullptr){
            return -1 ;
        }
        int height = max(heightoftree(root->left)+1, heightoftree(root->right)+1) ;
        return height ;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr){
            return 0 ;
        }

        queue<TreeNode*> pq ;
        pq.push(root) ;

        int diameter = 0 ;
        while(!pq.empty()){
            int n = pq.size() ;
            for(size_t i = 0 ; i < n ; i++){
                TreeNode *curr = pq.front() ;
                pq.pop() ;
                int temporary = heightoftree(curr->left) + heightoftree(curr->right) + 2 ;
                diameter = max(temporary, diameter) ;

                if(curr->left != nullptr){
                    pq.push(curr->left) ;
                }
                if(curr->right != nullptr){
                    pq.push(curr->right) ;
                }
            }
        }
        return diameter ;
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    return 0 ;
}