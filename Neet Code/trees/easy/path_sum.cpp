#include<bits/stdc++.h>
using namespace std ;


/*
https://leetcode.com/problems/path-sum/
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
Error in my solution is because of the following :-
first I have calculated all the leaf node values using in order traversal we can modify in order traversal to only capture leaf node values


    bool ancestors(TreeNode *root, int value, vector<int> &ans){
        if(root == nullptr){
            return false ;
        }
        if(root->val == value){
            return true ;
        }
        if((ancestors(root->left, value, count)) || (ancestors(root->right, value, count))){
            ans.push_back(root->val) ;
            return true ;
        }
        return false ;
    }

later I have used an ancestor function which is used to calculate ancestors of a node whose value is given as second parameter to the function
and first parameter is always root of the tree as if we are checking the node by using its value what we do is see if root is nullptr it means 
node value is not there so false, if we find the node with the given value we have found it so returned true, later what we did is we checked 
whether the value is present in the left subtree or right subtree so the node we are searching for will be in one of the left sub tree 
or right subtree from a given node so we took or if recursive function returs true then we are taking that node and adding it to the vector
as that node will be an ancestor of the node we are searching for 

Here we have modified our previous function slightly because we need sum of the ancestor node values so have modified the function slightly 

so now first calculated leaf node values stored in an array and now looped through this array and now for each leaf node value I have found 
the ancestors of it and added them all if there is a path whose sum is as given target we are done 


But the problem is that this is a binary tree there can be repetition of values unlike binary search tree it could work for binary search tree

so as we are looking for the node by its value and capturing all the ancestors of it there can be multiple nodes of same value so for a particular
node we miss some ancestors its because as follows 

                    1
                  /   \
                -2     -3
               /  \    /       
              1    3  -2
             /
            -1

            so for this if we check the output for this after running the following code u will get the following 

            0 -1 -1
            -1 3 2
            1 -2 -1

            for -2 leaf node which is a descendant of node -3 if we try to calculate the ancestor function 

            ancestors(root, -2, count)  

            so if we see here ancestors(root->left, value, count) this will be true so as in c++ if in a || b if a is true b condition is 
            not checked at all so we will miss the right side part of root node that is -3 node side 

            so for -2 as a leaf node we will end up with ancestors as just root node which is not correct over here 

            if so lets say our function is changed to the following 

            bool check1 = ancestors(root->left, value, count) ;
            bool check2 = ancestors(root->right, value, count) ;

            if(check1 || check2){
                count = count + root->val ;
                return true ;
            }

            then it considers both the right and left child as both are computed but the problem is that
            for the leaf node -2 it considers -3 node root node 1 as ancestors as here -2 is just child of the root node
            it is fine but what if -2 is not direct descendant of the root node but some where say last -1 leaf node child then
            the nodes -1 and 1 nodes will also be in the ancestor list of the leaf node -2 along with -3 node and root node which  is wrong so 
            changed the function to the following bottom one 
*/        
/*
class Solution {
public:
    void inorder_leaf(TreeNode *root, vector<int> &ans){
        if(root == nullptr){
            return ;
        }
        inorder_leaf(root->left, ans) ;
        if((root->left == nullptr) && (root->right == nullptr)){
            ans.push_back(root->val) ;
        }
        inorder_leaf(root->right, ans) ;
    }

    bool ancestors(TreeNode *root, int value, int &count){
        if(root == nullptr){
            return false ;
        }
        if(root->val == value){
            return true ;
        }
        if(ancestors(root->left, value, count) || ancestors(root->right, value, count) ){
            count = count + root->val ;
            return true ;
        }
        return false ;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr){
            return false ;
        }
        vector<int> leaf_values ;
        inorder_leaf(root, leaf_values) ;

        int n = leaf_values.size() ;
        bool ans = false ;
        int count ;
        for(int i = 0 ; i < n ; i++){
            count = 0 ;
            ancestors(root, leaf_values[i], count) ;
            cout<<count<<" " ;
            count = count + leaf_values[i] ;
            cout<<leaf_values[i]<<" "<<count<<endl ;
            if(count == targetSum){
                ans = true ;
                break ;
            }
        }
        return ans ;
    }
};
*/

/*
bfs it recursively calculates the path sum from a given node to the leaf node, the starting node is given as parameter which is the root in the 
parameters of the function we give sum = 0 as initial parameter there are two recursive calls inside the function to the left and right 
this is similar to like height recursive call we did before which considers both the right and left childs from a node so if we encounter a 
leaf we are done with one path sum so we push it to the ans a vector given as reference parameter which helps us to store all the path sums 
from a given node to the leaf nodes 

here we are not referencing sum because inside the function there are two recursive calls there will be two different paths from a node if we have
two children for it so right child node value should not be in the left child path so thats why we did not reference the sum 

if u want to add all the descendants from a given node then u can write a function smtng like this 

void bfs(TreeNode *root, int &sum){
    if(root == nullptr){
        return ;
    }
    sum = sum + root->val ;
    bfs(root->left, sum) ;
    bfs(root->right, sum) ;
}
as we want all the descendants sum we have to reference the sum 

while calling this function we have to give node whose descendants sum u want and sum value should be zero while passing it as reference

*/

class Solution {
public:
    void bfs(TreeNode *root, int sum, vector<int> &ans){
        if(root == nullptr){
            return ;
        }
        sum = sum + root->val ;
        if((root->left == nullptr) && (root->right == nullptr)){
            ans.push_back(sum) ;
        }
        bfs(root->left, sum, ans) ;
        bfs(root->right, sum, ans) ;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {

        vector<int> ans ;
        int sum = 0 ;
        bfs(root, sum, ans) ;

        for(size_t i = 0 ; i < ans.size() ; i++){
            if(ans[i] == targetSum){
                return true ;
            }
        }
        return false ;
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    return 0 ;
}