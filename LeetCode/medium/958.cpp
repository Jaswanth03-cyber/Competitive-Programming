#include<bits/stdc++.h>
using namespace std ;

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
    int height(TreeNode *root){
        if(root == nullptr){
            return -1 ;
        }
        int ans = max(height(root->left)+1, height(root->right)+1) ;
        return ans ; 
    }
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> pq ;
        pq.push(root) ;

        int size = 0 ;
        int count = 0 ;
        int maximum = height(root) ;
        bool ans = true ;
        bool stop = false ; 
        while(count < maximum- 1 ){
            size = pq.size() ;
            TreeNode *curr = pq.front() ;
            pq.pop() ;
            if(size != pow(2,count)){
                ans = false ;
                break ;
            }
            for(int i = 0 ; i < size ; i++){
                if(curr->left != nullptr){
                    pq.push(curr->left) ;
                }
                if(curr->right != nullptr){
                    pq.push(curr->right) ;
                }
            }
            count++ ;
        }
        size = pq.size() ;
        if(size != pow(2, count)){
            ans = false ;
        }
        else{
            for(int i = 0 ; i  < size ; i++){
                TreeNode *curr = pq.front() ;
                if((curr->left == nullptr) && (curr->right != nullptr)){
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