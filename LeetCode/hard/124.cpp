#include<bits/stdc++.h>
using namespace std ;


/*
https://leetcode.com/problems/binary-tree-maximum-path-sum/

35/94 test cases passed check it 
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
    void bfs(TreeNode *root, int sum, priority_queue<int> &ans){
        if(root == nullptr){
            return ;
        }
        sum = sum + root->val ;
        if((root->left == nullptr) && (root->right == nullptr)){
            ans.push(sum) ;
        }
        bfs(root->left, sum, ans) ;
        bfs(root->right, sum, ans) ;
    }
    int maxPathSum(TreeNode* root) {
        queue<TreeNode*> pq ;
        pq.push(root) ;

        int n = 0 ;
        int sum = 0 ;
        int temp = 0 ;
        int maximum = -1e8 ;
        while(!pq.empty()){
            n = pq .size() ;
            for(int i = 1 ; i <= n ; i++){
                priority_queue<int> ans ;
                TreeNode *curr = pq.front() ;
                pq.pop() ;
                bfs(curr,sum,ans) ;
                sum = 0 ;
                cout<<curr->val<<" "<<ans.size()<<" " ;
                if(ans.size() == 1){
                    temp = ans.top() ;
                    cout<<temp<<endl ;
                }
                else{
                    temp = temp + ans.top() ;
                    ans.pop() ;
                    temp = temp + ans.top() ;
                    if(curr->val < 0){
                        temp = temp + curr->val ;
                    }
                    else{
                        temp = temp - curr->val ;
                    }
                    cout<<temp<<endl ;
                }
                maximum = max(temp, maximum) ;
                temp = 0 ;
                if(curr->left != nullptr){
                    pq.push(curr->left) ;
                }
                if(curr->right != nullptr){
                    pq.push(curr->right) ;
                }
            }
        } 
        return maximum ;
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    return 0 ;
}