#include<bits/stdc++.h>
using namespace std ;

// Node should always be created using struct 
struct TreeNode{
    int val ;
    TreeNode* left ;
    TreeNode* right ;
    TreeNode(){
        this->val = 0 ;
        this->left = nullptr ;
        this->right = nullptr ;
    }
    TreeNode(int val){
        this->val = val ;
        this->left = nullptr ;
        this->right = nullptr ;
    }
};

class BST{
    TreeNode* root ;
    public:
    BST(){
        this->root = nullptr ; 
    }
    BST(int val){
        this->root = new TreeNode(val) ;
    }
    TreeNode* head(){
        return this->root ;
    }
    TreeNode* search(int val,TreeNode* node);
    int height(TreeNode* node);
    TreeNode* insert(int val,TreeNode* node);
    TreeNode* remove(int val,TreeNode* node);
    int depth_iterative(TreeNode* node);
    int depth_recursive(TreeNode* node,TreeNode* refnode,int &depth);
    void pre_order(TreeNode* node, vector<int> &arr);
    void in_order(TreeNode* node,vector<int> &arr);
    void post_order(TreeNode* node,vector<int> &arr);
    TreeNode* inorder_predecessor(TreeNode* node);
    TreeNode* inorder_successor(TreeNode* node);
    // void left_traversal(TreeNode* node,vector<int> &arr) ;
    // void right_traversal(TreeNode* node,vector<int> &arr) ;
    vector<int> left_level_order(TreeNode* node);
    vector<int> right_level_order(TreeNode* node);
    vector<vector<int>> level_order(TreeNode* node);
    void pathsum_to_leaves(TreeNode* node,vector<int> &arr,int sum);
    bool is_mirror_image(TreeNode* node1,TreeNode* node2) ;
    bool check_symetry(TreeNode* node) ;
};

int binarysearch(int val,vector<int> arr,int low,int high){
    if(low>high)return -1 ;
    else{
        int mid = (low+high)/2 ;
        if(arr[mid]==val){
            return mid ;
        }
        else if(arr[mid]>val){
            return binarysearch(val,arr,low,mid-1);
        }
        else{
            return binarysearch(val,arr,mid+1,high);
        }
    }
}

// leaf nodes were assumed to be at 0 height 
int BST::height(TreeNode* node){
    if(node==nullptr){
        return -1 ;
    }
    else{
        int left_height = height(node->left);
        int right_height = height(node->right);
        return 1 + max(left_height,right_height);
    }
}

int BST::depth_iterative(TreeNode* node){
    int d = 0 ;
    TreeNode* temp = root ;
    // if(node==temp) or if(node!=temp) is wrong bcoz two iterators cant be compared ! hence their values were compared .
    if(temp->val != node->val){
        while(temp->val != node->val){
            if(node->val > temp->val){
                temp = temp->right ;
                d = d + 1 ;
            }
            else{
                temp = temp->left ;
                d = d + 1 ;
            }
        }
    }
    return d ;
}

// depth parameter is sent by reference so that its value gets updated after every recursion .
// depth(TreeNode* node,int &depth) ==>> '&' referencing operator is important .
int BST::depth_recursive(TreeNode* node,TreeNode* refnode,int &depth){
    if(node->val == refnode->val){
        return depth ;
    }
    else{
        if(node->val > refnode->val){
            depth = depth + 1 ;
            depth_recursive(node,refnode->right,depth);
            // depth value gets updated after every recursion .
        }
        else{
            depth = depth + 1 ;
            depth_recursive(node,refnode->left,depth);
            // depth value gets updated after every recursion .
        }
    }
    return depth ;
}

TreeNode* BST::search(int val,TreeNode* node){
    // For checking node,nullptr can be compared ,but two node pointers can't be compared .
    if(node == nullptr){
        return nullptr ;
    }
    // Since two node pointers can't be compared their val's are compared .
    else if((node->val==val)){
        return node ;
    }
    else if(node->val > val){
        return search(val,node->left);
    }
    else if(node->val < val){
        return search(val,node->right);
    }
    return nullptr ;
}

TreeNode* BST::insert(int val,TreeNode* node){
    if((node==nullptr)&&(this->root==nullptr)){
        this->root = new TreeNode(val) ;
        return this->root ;
    }
    else if((node==nullptr)&&(this->root!=nullptr)){
        node = new TreeNode(val) ;
        return node ;
    }
    else if(node->val > val){
        node->left = insert(val, node->left) ;
        // if we write return insert(val,node->left) here it's wrong bcoz 
        // it doesn't connect the new nodes with the old nodes 
        // therefore node->left = insert(val,node->left) is correct 
    }
    else{
        node->right = insert(val, node->right) ;
        // if we write return insert(val,node->right) here it's wrong bcoz 
        // it doesn't connect the new nodes with the old nodes 
        // therefore node->right = insert(val,node->right) is correct 
    }
    return node ;
}

TreeNode* BST::remove(int val,TreeNode* node){
    if(node==nullptr){
       return nullptr ;
    }
    else if(node->val > val){
       node->left = remove(val,node->left);
    }
    else if(node->val < val){
        node->right = remove(val,node->right);
    }
    else{
        if((node->left==nullptr)&&(node->right==nullptr)){
            node = nullptr ;
            return nullptr ;
        }
        else if((node->left!=nullptr)&&(node->right==nullptr)){
            TreeNode* temp = node->left ;
            node->left = nullptr ;
            node = temp ;
            return node ;
        }
        else if((node->left==nullptr)&&(node->right!=nullptr)){
            TreeNode* temp = node->right ;
            node->right = nullptr ;
            node = temp ;
            return node ;
        }
        else{

            // TreeNode* temp = node->left ;
            // while(temp->right!=nullptr){
            //     temp = temp->right ;
            
            TreeNode* temp = inorder_predecessor(node);
            node->val = temp->val ;
            node->left = remove(temp->val,node->left);
            return node ;

            // TreeNode* temp = inorder_successor(node);
            // node->val = temp->val ;
            // node->right = remove(temp->val,node->right);
            // return node ;
        }
    }
    return node ;
}

TreeNode* BST::inorder_predecessor(TreeNode* node){
    vector<int> arr ;
    this->in_order(this->root,arr);
    int size = arr.size();
    int index = binarysearch(node->val,arr,0,size-1);
    if(index<=0){
        return nullptr ;
    }
    else{
        return search(arr[index-1],this->root) ;
    }
} 

TreeNode* BST::inorder_successor(TreeNode* node){
    vector<int> arr ;
    this->in_order(this->root,arr);
    int size = arr.size();
    int index = binarysearch(node->val,arr,0,size-1);
    if((index<0)||(index==size-1)){
        return nullptr ;
    }
    else{
        return search(arr[index+1],this->root) ;
    }
}

void BST::pre_order(TreeNode* node,vector<int> &arr){
    if(node==nullptr)return ;
    arr.push_back(node->val);
    pre_order(node->left,arr);
    pre_order(node->right,arr);
    return ;
}

void BST::post_order(TreeNode* node,vector<int> &arr){
    if(node==nullptr)return ;
    post_order(node->left,arr);
    post_order(node->right,arr);
    arr.push_back(node->val);
    return ;
}

void BST::in_order(TreeNode* node,vector<int> &arr){
    if(node==nullptr)return ;
    in_order(node->left,arr);
    arr.push_back(node->val);
    in_order(node->right,arr);
    return ;
}

vector<int> BST::left_level_order(TreeNode* node){
    vector<int> arr ;
    if(node == nullptr){
        return arr ;
    }
    queue<TreeNode*> q ;
    q.push(this->root) ;
    while(!q.empty()){
        int n = q.size() ;
        for(int i=0;i<n;i++){
            TreeNode* temp = q.front() ;
            q.pop() ;
            if(i == 0){
                arr.push_back(temp->val) ;
            }
            if(temp->left != nullptr){
                q.push(temp->left) ;
            }
            if(temp->right != nullptr){
                q.push(temp->right) ;
            }
        }
    }
    return arr ;
}

vector<int> BST::right_level_order(TreeNode* node){
    vector<int> arr ;
    if(node == nullptr){
        return arr ;
    }
    queue<TreeNode*> q ;
    q.push(this->root) ;
    while(!q.empty()){
        int n = q.size() ;
        for(int i=0;i<n;i++){
            TreeNode* temp = q.front() ;
            q.pop() ;
            if(i == 0){
                arr.push_back(temp->val) ;
            }
            if(temp->right != nullptr){
                q.push(temp->right) ;
            }
            if(temp->left != nullptr){
                q.push(temp->left) ;
            }
        }
    }
    return arr ;
}

vector<vector<int>> BST::level_order(TreeNode* node){
    vector<vector<int>> arr ;
    int n = depth_iterative(root) ;
    arr.resize(n) ;
    if(node == nullptr){
        return arr ;
    }
    int l = 0 ;
    queue<TreeNode*> q ;
    q.push(this->root) ;
    while(!q.empty()){
        int n = q.size() ;
        for(int i=0;i<n;i++){
            TreeNode* temp = q.front() ;
            q.pop() ;
            arr[l].push_back(temp->val) ;
            if(temp->left != nullptr){
                q.push(temp->left) ;
            }
            if(temp->right != nullptr){
                q.push(temp->right) ;
            }
        }
        l++ ;
    }
    return arr ;
}

void pathsum_to_leaves(TreeNode* node,vector<int> &arr,int sum){
    if(node==nullptr){
        return ;
    }
    if((node->left == nullptr)&&(node->right == nullptr)){
        arr.push_back(sum + node->val) ; 
        return ;
    }
    else if((node->left == nullptr)&&(node->right != nullptr)){
        pathsum_to_leaves(node->right, arr, sum + node->val) ;
    }
    else if((node->left != nullptr)&&(node->right == nullptr)){
        pathsum_to_leaves(node->left, arr, sum + node->val) ;
    }
    else{
        pathsum_to_leaves(node->left, arr, sum + node->val) ;
        pathsum_to_leaves(node->right, arr, sum + node->val) ;
    }
    return ;
}

bool BST::is_mirror_image(TreeNode* node1,TreeNode* node2){
    if((node1 == nullptr)&&(node2 == nullptr)){
        return true ;
    }
    else if((node1 != nullptr) && (node2 == nullptr)){
        return false ;
    }
    else if((node1 == nullptr) && (node2 != nullptr)){
        return false ;
    }
    else{
        if(node1->val == node2->val){
            bool bool_val = ((is_mirror_image(node1->left,node2->right))&&(is_mirror_image(node1->right,node2->left)));
            return bool_val ;
        }
        else{
            return false ;
        }
    }
    return true ;
}

bool BST::check_symetry(TreeNode* node){
    if(node == nullptr){
        return true ;
    }
    bool bool_val = is_mirror_image(node->left,node->right) ;
    return bool_val ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    BST *tree ;
    tree = new BST() ;
    tree->insert(150,tree->head()) ;
    tree->insert(40,tree->head()) ;
    tree->insert(80,tree->head()) ;
    tree->insert(30,tree->head()) ;
    tree->insert(70,tree->head()) ;
    tree->insert(90,tree->head()) ;
    tree->insert(140,tree->head()) ;
    tree->insert(180,tree->head()) ;
    tree->insert(120,tree->head()) ;
    tree->insert(170,tree->head()) ;
    tree->insert(190,tree->head()) ;
    tree->insert(10,tree->head()) ;
    vector<int> arr1;
    tree->in_order(tree->head(),arr1);
    cout<<"The elements in the BST are: { ";
    for(auto it=arr1.begin();it!=arr1.end();it++){
        cout<<*it<<" ";
    }
    cout<<"}"<<endl ;
    cout<<"The height of the node "<<150<<" is: "<<tree->height(tree->search(140,tree->head()))<<endl;
    cout<<"The depth of the node "<<120<<" is: "<<tree->depth_iterative(tree->search(120,tree->head()))<<endl;
    //cout<<"The depth of the node "<<80<<" is: "<<tree->depth_recursive(tree->search(80,tree->head()),d)<<endl;
    bool is_true = true ;
    for(auto it=arr1.begin();it!=arr1.end();it++){
        int d = 0 ;
        if((tree->depth_iterative(tree->search(*it,tree->head())))!=(tree->depth_recursive(tree->search(*it,tree->head()),tree->head(),d))){
            is_true = false ;
            cout<<tree->depth_iterative(tree->search(*it,tree->head())) - tree->depth_recursive(tree->search(*it,tree->head()),tree->head(),d)<<endl;
            cout<<*it<<endl ;
            break ;
        }
    }
    if(!is_true){
        cout<<"They both are different ."<<endl ;
    }
    else{
        cout<<"They are same ."<<endl ;
    }
    tree->remove(140,tree->head()) ;
    vector<int> arr2;
    tree->in_order(tree->head(),arr2);
    cout<<"The elements in the BST are: { ";
    for(auto it=arr2.begin();it!=arr2.end();it++){
        cout<<*it<<" ";
    }
    cout<<"}"<<endl ;
    cout<<"The height of the node "<<150<<" is: "<<tree->height(tree->search(150,tree->head()))<<endl;
    cout<<"The depth of the node "<<150<<" is: "<<tree->depth_iterative(tree->search(150,tree->head()))<<endl;
    
    vector<int> left = tree->left_level_order(tree->head()) ;
    cout<<"--------------------------------------------------------------------------------------------------------------------------------"<<endl ;
    cout<<"The nodes which were visible when we see the tree from left side are: ";
    for(auto it:left){
        cout<<it<<" ";
    }
    cout<<endl ;
    vector<int> right = tree->right_level_order(tree->head()) ;
    cout<<"The nodes which were visible when we see the tree from right side are: ";
    for(auto it:right){
        cout<<it<<" ";
    }
    cout<<endl ;
    cout<<"--------------------------------------------------------------------------------------------------------------------------------"<<endl ;

    return 0 ;
}

