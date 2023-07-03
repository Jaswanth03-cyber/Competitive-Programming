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

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans ;
        if(root == nullptr){
            return ans ;
        }      

        queue<TreeNode*> pq ;
        pq.push(root) ;

        while(!pq.empty()){
            int n = pq.size() ;
            for(int i = 1 ; i <= n ; i++){
                TreeNode *current = pq.front() ;
                pq.pop() ;
                if(i == n){
                    ans.push_back(current->val) ;
                }
                if(current->left != nullptr){
                    pq.push(current->left) ;
                }
                if(current->right != nullptr){
                    pq.push(current->right) ;
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