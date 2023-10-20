#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/count-good-nodes-in-binary-tree/
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
    void check(TreeNode* node, int maxsofar, int &count){
        if(node == nullptr){
            return ;
        }
        if(node->val >= maxsofar){
            count++ ;
        }
        maxsofar = max(maxsofar, node->val) ;
        check(node->left, maxsofar, count) ;
        check(node->right, maxsofar, count) ;
    }
    int goodNodes(TreeNode* root) {
        int count = 0 ;
        int maxsofar = INT_MIN ;
        check(root, maxsofar, count) ;
        return count ;
    }
};

/*
logic is simple we are maintaing the maxsofar in a path and note we are not sending the maxsofar as a reference
as it should not change it should be chaning only in a path so if so currval >= maxsofar that is a good node.
*/