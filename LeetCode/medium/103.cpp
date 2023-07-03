#include<bits/stdc++.h>
using namespace std ;


/*
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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
Nothing much pretty similar to level order traversal but here we should be careful as we are using deque for storing nodes 
so front and back will be a problem just see according to an example tree I have taken a char for dir if u are travelling left to right kept it as l
and vice versa 
*/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans ;
        if(root == nullptr){
            return ans ;
        }

        deque<TreeNode*> pq ; 
        pq.push_front(root) ;

        int n = 0 ;
        char dir = 'l' ;
        vector<int> level ;
        while(!pq.empty()){
            n = pq.size() ;
            for(int i = 0 ; i < n ; i++){
                if(dir == 'l'){
                    TreeNode *curr = pq.front() ;
                    pq.pop_front() ;
                    level.push_back(curr->val) ;
                    if(curr->left != nullptr){
                        pq.push_back(curr->left) ;
                    }
                    if(curr->right != nullptr){
                        pq.push_back(curr->right) ;
                    }
                }
                else{
                    TreeNode *curr = pq.back() ;
                    pq.pop_back() ;
                    level.push_back(curr->val) ;
                    if(curr->right != nullptr){
                        pq.push_front(curr->right) ;
                    }
                    if(curr->left != nullptr){
                        pq.push_front(curr->left) ;
                    }      
                }
            }
            if(dir == 'l'){
                dir = 'r' ;
            }
            else{
                dir = 'l' ;
            }
            ans.push_back(level) ;
            level.clear() ;
        }
        return ans ;
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    return 0 ;
}