#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/
*/
typedef long long ll ;
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q ;
        q.push(root) ;
        int size = 0 ;
        priority_queue<ll> pq ;
        while(!q.empty()){
            size = q.size() ;
            ll sum = 0 ;
            for(int i = 0; i < size ; i++){
                TreeNode* node = q.front() ;
                q.pop() ;
                sum += node->val ;
                if(node->left != nullptr){
                    q.push(node->left) ;
                }
                if(node->right != nullptr){
                    q.push(node->right) ;
                }
            }
            pq.push(sum) ;
        }
        size = pq.size() ;
        if(size < k){
            return -1 ;
        }
        k-- ;
        while(k--){
            pq.pop() ;
        }
        ll ans = pq.top() ;
        return ans ;
    }
};