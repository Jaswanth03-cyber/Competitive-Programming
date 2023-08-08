#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr){
            return root ;
        }

        queue<Node*> pq ;
        pq.push(root) ;
        int n = 0 ;

        while(!pq.empty()){
            n = pq.size() ;

            for(int i = 0 ; i < n ; i++){
                Node* node = pq.front() ;
                pq.pop() ;
                if(i == n - 1){
                    node->next = nullptr ;
                }
                else{
                    node->next = pq.front() ;
                }
                if(node->left != nullptr){
                    pq.push(node->left) ;
                }
                if(node->right != nullptr){
                    pq.push(node->right) ;
                }
            }
        }
        return root ; 
    }
};

