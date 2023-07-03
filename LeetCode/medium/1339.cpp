#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/*
My code passed just 52/54 did not pass because time limit exceeded 
*/
class Solution {
public:
    unsigned long int Sum(TreeNode *root){
        unsigned long int ans = 0 ;
        queue<TreeNode*> pq ;
        pq.push(root) ;

        while(!pq.empty()){
            int n = pq.size() ;
            for(int i = 1 ; i <= n ; i++){
                TreeNode *curr = pq.front() ;
                pq.pop() ;
                ans = ans + curr->val;
                if(curr->left != nullptr){
                    pq.push(curr->left) ;
                }
                if(curr->right != nullptr){
                    pq.push(curr->right) ;
                }
            }
        }
        return ans ;
    }
    int maxProduct(TreeNode* root) {

        unsigned long int total = 0 ;
        total = Sum(root) ;

        queue<TreeNode*> pq ;
        pq.push(root) ;

        unsigned long int maximum = 0 ;
        unsigned long int remaining = 0 ;
        unsigned long int temp = 0 ;
        unsigned long int modulo = 1e9 + 7 ;
        int n = 0 ;
        unsigned long int operation = 0 ;

        while(!pq.empty()){
            n =  pq.size() ;
            for(int i = 1 ; i <= n ; i++){
                TreeNode *curr = pq.front() ;
                pq.pop() ;
                temp = Sum(curr) ;
                remaining = total - temp ;
                operation = remaining*temp ;
                maximum = max(operation, maximum) ;

                if(curr->left != nullptr){
                    pq.push(curr->left) ;
                }
                if(curr->right != nullptr){
                    pq.push(curr->right) ;
                }
            }
        }
        int ans = maximum%modulo ;
        return ans ;
    }
};

/*
static int MOD=1e9+7;
class Solution {
public:
    long long totalTreeSum = 0, result=0;
    int SumUnder(TreeNode* root)             //Get the totalSum under the node `root` including root.
    {
        if(root == nullptr){
            return 0 ;
        }
        long long sum = SumUnder(root->left) + SumUnder(root->right) + root->val; //Get the sum of current subtree.
        result=max(result,sum*(totalTreeSum-sum));    //Get the max product after making current subtree as a separate tree
        return sum;
    }
    int maxProduct(TreeNode* root) 
    {
        totalTreeSum = SumUnder(root) ;
        SumUnder(root) ;
        return result%MOD ;
    }
};
*/

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;


    return 0 ;
}