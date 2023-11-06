#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
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
    void addancestor(TreeNode* curr, TreeNode* parent, unordered_map<TreeNode*, TreeNode*> &mp){
        if(curr == nullptr){
            return ;
        }
        if(parent == nullptr){
            mp.insert({curr, curr}) ; // this is for root 
        }
        else{
            mp.insert({curr, parent}) ;
        }

        addancestor(curr->left, curr, mp) ;
        addancestor(curr->right, curr, mp) ;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mp ;
        addancestor(root, nullptr, mp) ;
        unordered_map<int, int> visited ;

        int temp = k ;
        queue<TreeNode*> pq ;
        pq.push(target) ;
        int size = 0 ;

        while(temp > 0 && !pq.empty()){
            size = pq.size() ;
            for(int i = 0 ; i < size ; i++){
                TreeNode* node = pq.front() ;
                pq.pop() ;
                visited[node->val] = 1 ;
                if(node->left != nullptr && visited[node->left->val] != 1){
                    pq.push(node->left) ;
                }

                if(node->right != nullptr && visited[node->right->val] != 1){
                    pq.push(node->right) ;
                }

                if(mp[node] != nullptr && visited[mp[node]->val] != 1){
                    pq.push(mp[node]) ;
                }
            }
            temp-- ;
        }

        vector<int> ans ;
        while(!pq.empty()){
            ans.push_back(pq.front()->val) ;
            pq.pop() ;
        }

        return ans ;
    }
};


/*
so basically was doing dfs we can do dfs/bfs if we have a map of parents to the nodes so this helps in doing bfs normally like
a graph in general how we represent so we are going to the depth till temp is 0 i.e is k when temp is 1 all the nodes at distance k-1 are being processed
so all the nodes at distance k are going to be added and at the end temp becomes 0
*/