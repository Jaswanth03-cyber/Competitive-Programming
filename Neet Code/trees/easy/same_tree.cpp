#include<bits/stdc++.h>
using namespace std ;

// Definition for a binary tree node.

/*
https://leetcode.com/problems/same-tree/description/
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/*
Pre order traversal of a binary search tree is unique 

pre order traversal of a binary tree is unique if we replace where all the nullptr nodes with some constant value 
whose value is out of range of the node values so we compute both the pre order traversals where ever there is a nullptr 
we placed a value which is not in the node values lets say some 1e5 smtng here I have took 0 which is wrong consider some large value 

so a pre order traversal of a bst results in unique tree structure always
*/
class Solution {
public:
    void preorder(TreeNode *root, vector<int> &ans){
        if(root == nullptr){
            ans.push_back(0) ; // assuming 0 is not there in the nodes u can keep some constant value 
            return ;
        }
        ans.push_back(root->val) ;
        preorder(root->left, ans) ;
        preorder(root->right, ans) ;
    } 
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ans = true ;
        vector<int> p_ans ;
        vector<int> q_ans ;
        preorder(p, p_ans) ;
        preorder(q, q_ans) ;

        if(p_ans.size() != q_ans.size()){
            return false ;
        }   
        else{
            for(size_t i = 0 ; i < p_ans.size() ; i++){
                if(p_ans[i] != q_ans[i]){
                    return false ;
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