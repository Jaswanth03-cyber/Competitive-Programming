#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
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
    bool ancestor(TreeNode *root, int value, int &maximum){
        if(root == nullptr){
            return false ;
        }
        if(root->val == value){
            return true ;
        }
        if((ancestor(root->left, value, maximum)) || (ancestor(root->right, value, maximum))){
            maximum = max(maximum, abs(root->val - value)) ;
            return true ;
        }
        return false ;
    }
    int maxAncestorDiff(TreeNode* root) {

        queue<TreeNode*> pq ;
        pq.push(root) ;
        // vector<pair<int, vector<int>>> ancestors ;
        int maximum = 0 ;
        vector<pair<int, vector<int>>> ancestors ;
        while(!pq.empty()){
            int n = pq.size() ;
            for(int i = 1 ; i <= n ; i++){
                TreeNode *curr = pq.front() ;
                pq.pop() ;
                ancestor(root, curr->val, maximum) ;
                if(curr->left != nullptr){
                    pq.push(curr->left) ;
                }
                if(curr->right != nullptr){
                    pq.push(curr->right) ;
                }
            }
        }
        return maximum ;
    }
};


int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;


    return 0 ;
}