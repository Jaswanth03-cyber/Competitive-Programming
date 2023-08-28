#include<bits/stdc++.h>
using namespace std ;
// defining node


/*

BFS of a tree starting at the node will give us a level order traversal of the tree 
implement right, left level order traversals and also implement a function which returns a pointer to the
root of a tree which is a mirror image of the given tree

Number of binary search trees of n nodes (2n)! / n! * (n+1)!
*/
struct node{
    int data ;
    node* left ;
    node* right ;
};
// for new node creation 
node* Newnode(int a){
    node* n = new node ;
    n->data = a ;
    n->left = nullptr ;
    n->right = nullptr ;
    return n ;
}
int change(int *b){
    *b = (*b)*(*b) ;
    return *b ;
}
// class BST
class binarysearchtree{

    private: 
    node *root ;

    public:
// constructor 
    binarysearchtree(int a){
        root = Newnode(a) ;
    }
// constructor with root as nullptr 
    binarysearchtree(){
        root = nullptr ;
    }

    node* getroot(){
        return this->root ;
    }
// insertion of new node 
    node* insert(node *n, int a){
        if(n == nullptr){
            n = Newnode(a) ;
            return n ;
        }
        if(n->data > a){
            n->left = insert(n->left,a) ;     // not only insert(n->left,a)
        }
        if(n->data < a){
            n->right = insert(n->right,a) ; // not only insert(n->right,a)
        }
        return n ; // note this return and see main function T.insert(n,number) there we did not write node* m = T.insert() just 
        // wrote T.insert while changing a variable we can just write function name even though not equating to a variable of return type 
        // but that return is used to return the node in the reccurssive calls 
    }
// inorder traversal of the tree  (left,root,right)
    void inorder(node *n){
        if(n == nullptr){
            return ;
        }
        inorder(n->left) ;
        cout<<n->data<<" " ;
        inorder(n->right) ;
    }
// pre order traversal of the tree (root,left,right)
/*
pre order traversal of a binary search tree will be unique so a pre order traversal will result in a unique binary search tree 

pre order of a binary tree will be unique if u place a constant value in the place of missing nodes to compare two trees whether same or not
*/
    void preorder(node *n){
        if(n == nullptr){
            return ;
        }
        cout<<n->data<<" " ;
        preorder(n->left) ;
        preorder(n->right) ;
    }

/*
function two compare two given binary trees whether they have same structure or not 
*/
    void preorder_compare(node *n, vector<int> &ans){
        if(n == nullptr){
            ans.push_back(0) ;
            return ;
        }
        ans.push_back(n->data) ;
        preorder_compare(n->left, ans) ;
        preorder_compare(n->right, ans) ;
    }
// post order traversal of the tree (left,right,root)
    void postorder(node *n){
        if(n == nullptr){
            return ;
        }
        postorder(n->left) ;
        postorder(n->right) ;
        cout<<n->data<<" " ;
    }

// left view level order for clarification see geeks for geeks 
    vector<int> left_view_level_order(node *n){
        vector<int> result ;
        if(n == nullptr){
            return result ;
        }
        queue<node*> pq ; 
        result.push_back(n->data) ;
        pq.push(n) ;

        while(!pq.empty()){
            int n = pq.size() ;

            for(int i = 1 ; i <= n ; i++){
                node* top = pq.front() ;
                pq.pop() ;
                if(i == 1){
                    result.push_back(top->data) ;
                }
                if(top->left != nullptr){
                    pq.push(top->left) ;
                }
                if(top->right != nullptr){
                    pq.push(top->right) ;
                }
            }
        }
        return result ;
    }

// right view level order traversal of a tree 

    vector<int> right_view_level_order(node *n){
        vector<int> result ;
        if(n == nullptr){
            return result ;
        }
        queue<node*> pq ; 
        result.push_back(n->data) ;
        pq.push(n) ;

        while(!pq.empty()){
            int n = pq.size() ;

            for(int i = 1 ; i <= n ; i++){
                node* top = pq.front() ;
                pq.pop() ;
                if(i == n){
                    result.push_back(top->data) ;
                }
                if(top->left != nullptr){
                    pq.push(top->left) ;
                }
                if(top->right != nullptr){
                    pq.push(top->right) ;
                }
            }
        }
        return result ;
    }
// level order array of a tree this is nothing but storing the nodes if we do bfs starting from root 

    vector<int> level_order_view(node *root){
        vector<int> ans ;
        queue<node*> pq ;
        pq.push(root) ;
        
        while(!pq.empty()){
            int n = pq.size() ;
            for(int i = 1; i <= n ; i++){
                node *curr = pq.front() ;
                pq.pop() ;
                ans.push_back(curr->data) ;
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
// function that turns this tree into a tree which is mirror of original one 

    void *mirror_image(node *root){
        if (root == nullptr){
            return ;
        }
 
        queue<node*> q;
        q.push(root);
 
    // Do BFS. While doing BFS, keep swapping
    // left and right children
        while (!q.empty()) {
        // pop top node from queue
            node* curr = q.front();
            q.pop();

        // swap left child with right child
            swap(curr->left, curr->right);

        // swap is a function which swaps two variable values irrespective of the data type 
 
        // push left and right children
            if (curr->left){
                q.push(curr->left);
            }
            if (curr->right){
                q.push(curr->right);
            }
        }
    }

// if given a value of a node we will get the ancestors of this node also give a vector as a parameter to store all those values
// and always first parameter should be root node itself in the begining, second parameter ancestors of that value node we require ans vector to store the ancestor values 
// we can change this function to calculate the sum of ancestors values or find the maximum of all the ancestors etc... 
// this works only for binary search tree but not for binary tree and also in binary search tree nodes with same values should not be there 
    bool ancestors(node *root, int value, vector<int> &ans){
        if(root == nullptr){
            return false ;
        }

        if(root->data == value){
            return true ;
        }
        if((ancestors(root->right, value, ans)) || (ancestors(root->left, value, ans))){
            ans.push_back(root->data) ;
            return true ;
        }
        return false ;
    }

// u could get descendants of a node given as parameter 
    vector<int> descendants(node *n){
        vector<int> ans ;

        queue<node*> pq ;
        pq.push(n) ;

        while(!pq.empty()){
            int n = pq.size() ;

            for(int i = 1 ; i <= n ; i++){
                node *curr = pq.front() ;
                pq.pop() ;

                ans.push_back(curr->data) ;
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

// sum of the descendants of a given node 
    int sumofdescendants(node *n){
        if(n == nullptr){
            return 0 ;
        }
        int total = sumofdescendants(root->left) + sumofdescendants(root->right) + root->data ;
        return total ;
    }

// sum of node values from root to leaf of all the leaves inputs give sum as 0 and an empty integer vector 

    void bfs(node *root, int sum, vector<int> &ans){
        if(root == nullptr){
            return ;
        }
        sum = sum + root->data ;

        if((root->left == nullptr) && (root->right == nullptr)){
            ans.push_back(sum) ;
        }
        bfs(root->left, sum, ans) ;
        bfs(root->right, sum, ans) ;
    }
// to check whether a tree is symmetric or not that is it is mirror image of itself 
bool isMirror(node* root1, node* root2){
    if (root1 == nullptr && root2 == nullptr){
        return true;
    }
    if ((root1 != nullptr) && (root2 != nullptr) && (root1->data == root2->data)){
        if((isMirror(root1->left, root2->right)) && (isMirror(root1->right, root2->left))){
            return true ;
        }
    }
    return false;
}

bool issymmetric(node *root){
    bool result = false ;

    result = isMirror(root, root) ;
    return result ;
}

// searching for a node with a given value 
    node* search(node* n, int a){
        if(n->data == a){
            // cout<<"The node with value "<<a<<" is found"<<endl ;
            return n ;
        }
        if(n->data > a){
            return search(n->left,a) ;
        }
        if(n->data < a){
            return search(n->right,a) ;
        }
        return nullptr ;
    }
// In order successor of a given node is a node with the min value of all the nodes whose keys are greater than the given key
/*
Here these both functions do not give in order predecessor/ in order sucessor for a given leaf node but actually there exists
both predecessor and successor according to the definiton 

so one way we can do this is by taking inorder traversal of the tree and and take the val just before the value for which we need predecessor
and the next immediate value for the in order successor and have a search for those two values from root which gives pointers to those nodes
which are predecessor and successor for that leaf node and also Note that pointers which we get are copy of the original pointers 

In Delete function we used in order successor and predecesor as there we calculate only for non leaf nodes only 
only in non leaf nodes these two functions which I wrote will be useful.
*/
    node* inorder_sucessor(node *n){
        node *current = n->right ;
        while(current->left != nullptr && current != nullptr){
            current = current->left ;
        }
        return current ;
    }
    node *inorder_predecessor(node *n){
        node *current = n->left ;
        while(current->right != nullptr && current != nullptr){
            current = current->right ;
        }
        return current ;
    }
// deleting a node contains a total of three cases 
/*
Note while deleting TreeNode* node = search(root, val) ;
this node will get another copy of that node which u are searching if u delete I mean if u write the following in the code 
delete node ; // or node = nullptr ; both are same 
then it means it will delete that copy node only not the original node. 
so thats why in delete we did not do this 

TreeNode* node = search(root, val) ;
delete node ;  
this is an error we can not do that it does not delete original node so we use this way, this way I mean use this recursion 

write in on a pen and paper for a tree and check .
*/
    node* Delete(node *n, int a){
        if(n == nullptr){
            return n ;
        } 
    // If the key to be Deleted is smaller than the root's key then it lies in left subtree
        if(n->data > a){
            n->left = Delete(n->left,a) ;
        }
    // If the key to be Deleted is greater than the root's key, then it lies in right subtree
        else if(n->data < a){
            n->right = Delete(n->right,a) ;
        }
    // if key is same as root's key, then This is the node to be Deleted
        else{
        // node with no children case 1 
            if(n->right == nullptr && n->left == nullptr){
                return nullptr ;
            }
    // Node with only one child case 2
        // has only left child 
            else if(n->right == nullptr){
                node *temp = n->left ;
                delete n ;
                return temp ;
            }
        // has only right child
            else if(n->left == nullptr){
                node *temp = n->right ;
                delete n ;
                return temp ;
            }
        // has both the children case 3 we can do any of the following two cases both results a bst but different bsts 

        
        /*
        Here if replacing with in order predecessor this is the code 
        node *temp = inorder_predecessor(n) ;
        cout<<temp->data<<endl ;
        n->data = temp->data ;
        n->left = Delete(n->left, temp->data) ;
        */
        
        // If we want to replace it by inorder successor this is the code 
        // copying the data of inorder sucessor 
            // cout<<temp->data<<endl ;
            node *temp = inorder_sucessor(n) ;
            n->data = temp->data ;
            n->right = Delete(n->right, temp->data);
        }
        return n ;
    }

/*
In a tree data structure, the total number of egdes from root node to a particular node is called as DEPTH of that Node. 
*/
    void getdepth(node *n, int a, int &depth){
        if(n == nullptr){
            return ;
        }
        if(n->data == a){
            return ;  
        }
        else if(n->data > a){
            depth++ ;
            getdepth(n->left, a, depth) ;
        }
        else{
            depth++ ;
            getdepth(n->right, a, depth) ;
        }
    }

/*
In a tree data structure, the total number of edges from leaf node to a particular node in the longest path is called 
as height of that Node. Maximum height can be from any of the left or right so at every call we take 
maximum of the two(left and right) at every call 
*/
    int heightoftree(node *n){
        if(n == nullptr){
            return -1 ; 
        }
        return max(heightoftree(n->left) + 1, heightoftree(n->right) + 1) ;
    }

/*
Height of the node can be calculated simillarly like height of a tree only thing is that we need to think that node as the root
*/
    int getnodeheight(node *n, int a){
        int height = 0 ;

        node *required_node = search(n, a) ;

        height = heightoftree(required_node) ;

        return height ;
    }

/*
Diameter is nothing but the maximum length of a path between any two nodes in the tree 

this is wrong implementation as longest path need not always pass through root of the tree 
*/
    int diameteroftree(node *n){
        int diameter_tree = 0 ;
        int height_left = heightoftree(n->left) ;
        int height_right = heightoftree(n->right) ;

        diameter_tree = height_left + height_right + 2 ;

        return diameter_tree ;
    }
};


/*
Here in Delete node when we have two children for the node which we want to Delete we replace it by in order sucessor and Delete 
it we can also do this we can replace it by in order predecessor and Delete it for that implementation I will keep it in the comments

*/
int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;


    binarysearchtree T(100) ;
    node *n = T.getroot() ;
    node *m =  T.insert(n,50) ;
    T.insert(n,150) ;
    T.insert(n,40) ;
    T.insert(n,80) ;
    T.insert(n,30)  ;
    T.insert(n,70) ;
    T.insert(n,90) ;
    T.insert(n,140) ;
    T.insert(n,180) ;
    T.insert(n,120) ;
    T.insert(n,170) ;
    T.insert(n,190) ;
    T.inorder(n) ;
    cout<<endl ;
    T.postorder(n) ;
    cout<<endl ;
    T.preorder(n) ;
    cout<<endl ;

    int depth1 = 0 ;
    T.getdepth(n, 100, depth1);
    cout<<"depth of 100 is : "<<depth1<<endl ;
    int depth2 = 0 ;
    T.getdepth(n, 80, depth2);
    cout<<"depth of 80 is : "<<depth2<<endl ;
    int depth3 = 0 ;
    T.getdepth(n, 50, depth3);
    cout<<"depth of 50 is : "<<depth3<<endl ;
    int depth4 = 0 ;
    T.getdepth(n, 70, depth4);
    cout<<"depth of 70 is : "<<depth4<<endl ;
    int depth5 = 0 ;
    T.getdepth(n, 140, depth5) ; 
    cout<<"depth of 140 is : "<<depth5<<endl ;

    int depth6 = 0 ;
    T.getdepth(n, 180, depth6);
    cout<<"depth of 180 is : "<<depth6<<endl ;

    int depth7 = 0 ;
    T.getdepth(n, 120, depth7);
    cout<<"depth of 120 is : "<<depth7<<endl ;

    int depth8 = 0 ;
    T.getdepth(n, 30, depth8);
    cout<<"depth of 30 is : "<<depth8<<endl ;

    int depth9 = 0 ;
    T.getdepth(n, 90, depth9);
    cout<<"depth of 90 is : "<<depth9<<endl ;


    int height = T.heightoftree(n) ;
    cout<<"height of the tree is : "<<height<<endl ; 


    int height_of_node1 = T.getnodeheight(n, 50) ;
    cout<<"height of node 50 is : "<<height_of_node1<<endl ;

    int height_of_node2 = T.getnodeheight(n, 80) ;
    cout<<"height of node 80 is : "<<height_of_node2<<endl ;

    int height_of_node3 = T.getnodeheight(n, 100) ;
    cout<<"height of node 100 is : "<<height_of_node3<<endl ;

    int height_of_node4 = T.getnodeheight(n, 180) ;
    cout<<"height of node 180 is : "<<height_of_node4<<endl ;

    int height_of_node5 = T.getnodeheight(n, 100) ;
    cout<<"height of node 100 is : "<<height_of_node5<<endl ;

    int height_of_node6 = T.getnodeheight(n, 170) ;
    cout<<"height of node 170 is : "<<height_of_node6<<endl ;

    int height_of_node7 = T.getnodeheight(n, 40) ;
    cout<<"height of node 140 is : "<<height_of_node7<<endl ;

    int height_of_node8 = T.getnodeheight(n, 150) ;
    cout<<"height of node 150 is : "<<height_of_node8<<endl ;

    int height_of_node9 = T.getnodeheight(n, 90) ;
    cout<<"height of node 90 is : "<<height_of_node9<<endl ;

    int height_of_node10 = T.getnodeheight(n, 30) ;
    cout<<"height of node 30 is : "<<height_of_node10<<endl ;

    int diameter_tree_1 = 0 ;
    diameter_tree_1 = T.diameteroftree(n) ;
    cout<<"diameter of the tree is : "<<diameter_tree_1<<endl ;

    T.Delete(n, 150) ;
    T.Delete(n, 120) ;
    T.Delete(n, 40) ;
    T.Delete(n, 190) ;

    int depth_1 = 0 ;
    T.getdepth(n, 100, depth_1);
    cout<<"depth of 100 is : "<<depth_1<<endl ;
    int depth_2 = 0 ;
    T.getdepth(n, 80, depth_2);
    cout<<"depth of 80 is : "<<depth_2<<endl ;
    int depth_3 = 0 ;
    T.getdepth(n, 50, depth_3);
    cout<<"depth of 50 is : "<<depth_3<<endl ;
    int depth_4 = 0 ;
    T.getdepth(n, 70, depth_4);
    cout<<"depth of 70 is : "<<depth_4<<endl ;
    int depth_5 = 0 ;
    T.getdepth(n, 140, depth_5);
    cout<<"depth of 140 is : "<<depth_5<<endl ;

    int depth_6 = 0 ;
    T.getdepth(n, 180, depth_6);
    cout<<"depth of 180 is : "<<depth_6<<endl ;

    int depth_7 = 0 ;
    T.getdepth(n, 30, depth_7);
    cout<<"depth of 30 is : "<<depth_7<<endl ;

    int depth_8 = 0 ;
    T.getdepth(n, 90, depth_8);
    cout<<"depth of 90 is : "<<depth_8<<endl ;

    int depth_9 = 0 ;
    T.getdepth(n, 170, depth_9) ;
    cout<<"depth of 170 is : "<<depth_9<<endl ; 

    int height_1 = T.heightoftree(n) ;
    cout<<"height of the tree is : "<<height_1<<endl ; 


    int height_of_node_1 = T.getnodeheight(n, 50) ;
    cout<<"height of node 50 is : "<<height_of_node_1<<endl ;

    int height_of_node_2 = T.getnodeheight(n, 80) ;
    cout<<"height of node 80 is : "<<height_of_node_2<<endl ;

    int height_of_node_3 = T.getnodeheight(n, 100) ;
    cout<<"height of node 100 is : "<<height_of_node_3<<endl ;

    int height_of_node_4 = T.getnodeheight(n, 180) ;
    cout<<"height of node 180 is : "<<height_of_node_4<<endl ;

    int height_of_node_6 = T.getnodeheight(n, 170) ;
    cout<<"height of node 170 is : "<<height_of_node_6<<endl ;

    int height_of_node_7 = T.getnodeheight(n, 30) ;
    cout<<"height of node 30 is : "<<height_of_node_7<<endl ;

    int height_of_node_8 = T.getnodeheight(n, 140) ;
    cout<<"height of node 140 is : "<<height_of_node_8<<endl ;

    int height_of_node_9 = T.getnodeheight(n, 90) ;
    cout<<"height of node 90 is : "<<height_of_node_9<<endl ;

    int height_of_node_10 = T.getnodeheight(n, 70) ;
    cout<<"height of node 70 is : "<<height_of_node_10<<endl  ;

    int diameter_tree_2 = 0 ;
    diameter_tree_2 = T.diameteroftree(n) ;
    cout<<"diameter of the tree is : "<<diameter_tree_2<<endl ;

 
    return 0 ;
}