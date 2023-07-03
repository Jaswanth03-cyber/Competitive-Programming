#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/find-bottom-left-tree-value/
*/

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
calculate level order traversal left view in that bottom left one is required in the left view traversal last node value is required
*/
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {

        queue<TreeNode*> pq ; 
        pq.push(root) ;

        vector<int> ans ;
        int result = 0 ;
        while(!pq.empty()){

            int n = pq.size() ;
            for(int i = 1 ; i <= n ; i++){
                TreeNode *curr = pq.front() ;
                pq.pop() ;

                if(i == 1){
                    ans.push_back(curr->val) ;
                }
                if(curr->left != nullptr){
                    pq.push(curr->left) ;
                }
                if(curr->right != nullptr){
                    pq.push(curr->right) ;
                }
            }
        } 

        int n = ans.size() ;
        result = ans[n-1] ;
        return result ;
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    return 0 ;
}