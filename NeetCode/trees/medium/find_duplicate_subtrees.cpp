#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/find-duplicate-subtrees/
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// class Solution {
// public:

//     void preorder(TreeNode* node, string &temp){
//         if(node== nullptr){
//             temp = temp + 'a' ;
//         }
//         temp = temp + to_string(node->val) ;
//         preorder(node->left, temp) ;
//         preorder(node->right, temp) ;
//     }

//     vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
//         queue<TreeNode*> pq ;
//         pq.push(root) ;
//         vector<TreeNode*> ans ;
//         map<string, pair<TreeNode*, int>> mp ;
//         while(!pq.empty()){
//             int size = pq.size() ;
//             for(int i = 0 ; i < size ; i++){
//                 TreeNode* node = pq.front() ;
//                 pq.pop() ;
//                 if(node->left != nullptr){
//                     pq.push(node->left) ;
//                     leftchild = node->left->val ;
//                 }

//                 if(node->right != nullptr){
//                     pq.push(node->right) ;
//                     rightchild = node->right->val ;
//                 }
//                 string temp = "" ;
//                 preorder(node, temp) ;
//                 if(mp.find(temp) != mp.end()){
//                     if(mp[temp].second == 1){
//                         ans.push_back(node) ;
//                     }
//                     mp[temp].second++ ;
//                 }
//                 else{
//                     mp.insert({temp, {node, 1}}) ;
//                 }
//             }
//         }
//         return ans ;
//     }
// };

/*
In the above code I had a problem with the foloowing tree structure 
2, 1, 11, 11, null, null, 1, null so thats why tried to add a 'l' before left preorder and 'r' before right preorder to temp and we can do that
but see tha algo is taking around O(n^3) as bfs n, for pre order worst case n and for checking whether a string is present or not for n 

so thats why we came up with a solution while doing preorder itself check for duplicates here we go from leaves to root 
first call is done by root but first insertion in the map will be a leaf 

mp has the string which is a encoded vale of a unique binary tree and is mapped to an int if already present and present only once then
add the node to the answer if present more than once no need we have already added its duplicate.

Came up with the idea but TLE. :(
*/
class Solution {
public:
    string preorder(TreeNode* node, map<string, int> &mp, vector<TreeNode*> &ans){
        if(node == nullptr){
            return "null"; 
        }
        string temp = 'p' + to_string(node->val) +  'l' + preorder(node->left, mp, ans) + 'r' + preorder(node->right, mp, ans) ;

        if(mp.find(temp) != mp.end()){
            if(mp[temp] == 1){
                ans.push_back(node) ;
            }
            mp[temp]++ ;
        }
        else{
            mp[temp]++  ;
        }
        return temp ;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans ;
        map<string, int> mp ;
        preorder(root, mp, ans) ;
        return ans ;
    }
};