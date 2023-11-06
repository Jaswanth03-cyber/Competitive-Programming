#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/cousins-in-binary-tree-ii/
*/

class Solution {
public:
    void bfs(TreeNode* node, vector<int> &temp){
        queue<TreeNode*> pq ;
        pq.push(node) ;

        int size = 0 ;
        while(!pq.empty()){
            int currsum = 0 ;
            size = pq.size() ;
            for(int i = 0 ; i < size ; i++){
                TreeNode* Node = pq.front() ;
                pq.pop() ;
                currsum += Node->val ;
                if(Node->left != nullptr){
                    pq.push(Node->left) ;
                }
                if(Node->right != nullptr){
                    pq.push(Node->right) ;
                }
            }
            temp.push_back(currsum) ;
        }
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> temp ;
        TreeNode* node = root ;
        bfs(node, temp) ;  
        int counter = 1 ;
        node = root ;
        queue<TreeNode*> pq ;
        pq.push(node) ;
        int size = 0 ;
        node->val = 0 ;
        while(!pq.empty()){
            size = pq.size() ;
            for(int i = 0 ; i < size ; i++){
                TreeNode* Node = pq.front() ;
                pq.pop() ;
                int sum = 0 ;
                if(Node->left != nullptr){
                    sum += Node->left->val ;
                    pq.push(Node->left) ;
                }
                if(Node->right != nullptr){
                    sum += Node->right->val ;
                    pq.push(Node->right) ;
                }

                if(sum != 0){
                    if(Node->left != nullptr){
                        Node->left->val = temp[counter] - sum ;
                    }
                    if(Node->right != nullptr){
                        Node->right->val = temp[counter] - sum ;
                    }
                }
            }
            counter++ ;
        }
        return root ;
    }
};

/*
two times dfs, in one dfs I have found the total sum of a level I have subtracted value of sum of childs nodes from the total sum and 
made it equal to the child values
be carefull sum == 0 means all nullptrs and counter starts from 1 not 0 as 0 corresponds to root level sum
*/