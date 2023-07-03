#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/same-tree/
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
    void preorder(TreeNode *root, vector<int> &ans){
        if(root == nullptr){
            ans.push_back(1e5) ; // assuming 0 is not there in the nodes u can keep some constant value 
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
            ans = false ;
            return ans ; 
        }   
        else{
            for(size_t i = 0 ; i < p_ans.size() ; i++){
                if(p_ans[i] != q_ans[i]){
                    ans = false ;
                    break ;
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