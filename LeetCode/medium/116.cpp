#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
*/

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr){
            return root ;
        }

        queue<Node*> pq ;
        pq.push(root) ;
        int size = 0 ;

        while(!pq.empty()){
            size = pq.size() ;
            for(int i = 0 ; i < size ; i++){
                Node* node = pq.front() ;
                pq.pop() ;
                if(i == size -1){
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