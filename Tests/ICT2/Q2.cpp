#include <bits/stdc++.h>
using namespace std ;


struct TreeNode{
    int data ;
    TreeNode* left ;
    TreeNode* right ;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {} 
};

/*
Note there will be problems when node is root write conditions well
*/
int checkMax(TreeNode* root){
    queue<TreeNode*> pq ;
    pq.push(root) ;
    int n = 0 ;
    stack<pair<int, int>> st ;
    while(!pq.empty()){
        int size = pq.size() ;
        n = n + size ;
        for(int i = 0 ; i < size ; i++){
            TreeNode* node = pq.front() ;
            pq.pop() ;

            if(node->left != nullptr){
                pq.push(node->left) ;
                st.push({node->left->data, node->data}) ;
            }

            if(node->right != nullptr){
                pq.push(node->right) ;
                st.push({node->right->data, node->data}) ;
            }
        }
    }

    vector<int> ChildrenCount(n, 0) ;

    while(!st.empty()){
        int parent = st.top().second ;
        int child = st.top().first ;
        ChildrenCount[parent] = ChildrenCount[parent] + 1 + ChildrenCount[child] ;
        st.pop() ;
    }

    vector<int> importance(n, 0) ;

    pq.push(root) ;
    int k = 0 ;
    int maximum = 0 ;
    while(!pq.empty()){
        int size = pq.size() ;
        for(int i = 0 ; i < size ; i++){
            TreeNode* node = pq.front() ;
            pq.pop() ;
            int one = 0 ;
            int two = 0 ;
            if(node->left != nullptr){
                pq.push(node->left) ;
                one = ChildrenCount[node->left->data] ;
            }
            else{
                one = -1 ;
            }

            if(node->right != nullptr){
                pq.push(node->right) ;
                two = ChildrenCount[node->right->data] ;
            }
            else{
                two = -1 ;
            }

            if(one == -1 && two == -1){
                importance[k] = n-1 ;
            }
            else if(two == -1){
                if(node->data != root->data){
                    importance[k] = (one+1)*(n-(one+2)) ;
                }
                else{
                    importance[k] = one+1 ;
                }
            }
            else if(one == -1){
                if(node->data != root->data){
                    importance[k] = (two+1)*(n-(two+2)) ;
                }
                else{
                    importance[k] = two + 1 ;
                }
            }
            else if(node->data != root->data){
                importance[k] = (one+1)*(two+1)*(n- (two+one+3)) ;
            }
            else{
                importance[k] = (one+1)*(two+1) ;
            }

            // cout<<node->data<<" "<<importance[k]<<endl ;
            maximum = max(importance[k], maximum) ;
            k++ ;
        }
    }

    int count = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(importance[i] == maximum){
            count++ ;
        }
    }

    return count ;
}

TreeNode* buildTreeFromParentIndices(const vector<int> &parentindices){
    int size = parentindices.size() ;
    vector<TreeNode*> nodes(size, nullptr) ;
    TreeNode* root = nullptr ;

    for(int i = 0 ; i < size ; i++){
        if(nodes[i] == nullptr){
            nodes[i] = new TreeNode(i) ;
        }

        int parentindex = parentindices[i] ;

        if(parentindex == -1){
            root = nodes[i] ;
        }
        else{
            if(nodes[parentindex] == nullptr){
                nodes[parentindex] = new TreeNode(parentindex) ;
            }

            if(nodes[parentindex]->left == nullptr){
                nodes[parentindex]->left = nodes[i] ;
            }
            else{
                nodes[parentindex]->right = nodes[i] ;
            }
        }
    }
    return root ;
}

int main(){
    int n = 0 ;
    cin>>n ;
    vector<int> parentindices(n, 0) ;

    for(int i = 0 ; i < n ; i++){
        cin>>parentindices[i] ;
    }
    TreeNode* root = buildTreeFromParentIndices(parentindices) ;

    int ans = checkMax(root) ;
    cout<<ans<<endl ;

    return 0 ;
}