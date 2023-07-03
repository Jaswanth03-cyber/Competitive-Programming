#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/subtree-of-another-tree/
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
Pre order traversal of a binary search tree is unique 

pre order traversal of a binary tree is unique if we replace where all the nullptr nodes with some constant value 
whose value is out of range of the node values so we compute both the pre order traversals where ever there is a nullptr 
we placed a value which is not in the node values lets say some 1e5 smtng here I have took 0 which is wrong consider some large value 

so a pre order traversal of a bst results in unique tree structure always


so we are given a subroot node we calculated its pre order and also the big tree pre order we check 
if there exists a array in the main one which contains subtree pre order array we see whether all the elements are 
there are not as it is a binary tree similar value nodes can be there so check whether all ther nodes correctly match or not here structure is also
important be carefull just check previous submissions errors 
*/

class Solution {
public:
    void preorder(TreeNode *root, vector<int> &ans){
        if(root == nullptr){
            ans.push_back(1e5) ;
            return ;
        }
        ans.push_back(root->val) ;
        preorder(root->left, ans) ;
        preorder(root->right, ans) ;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot){

        vector<int> ans1 ;
        vector<int> ans2 ;
        preorder(root, ans1) ;
        preorder(subRoot, ans2) ;
        int count = 0 ; // variable to count number of nodes that are matching this is no of use ig 
        int size = ans2.size() ;
        bool result = false ;
        for(int i = 0 ; i < ans1.size() ; i++){
            if(ans1[i] == ans2[0]){
                count++ ;
                for(int j = 1 ; j < ans2.size() ; j++){
                    if(ans1[i+j] == ans2[j]){
                        if(j == ans2.size() - 1){ // this condition is because to say all the nodes are found because it is a binary tree there can be same value in many nodes once see old submissions of this problem
                            return true ;
                        }
                        count++ ;
                    }
                    else{
                        count = 0 ;
                        break ;
                    }
                }
            }
        }
        return result ;
    }
};


int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    return 0 ;
}