#include<bits/stdc++.h>
using namespace std ;
// defining node


/*

BFS of a tree starting at the node will give us a level order traversal of the tree 
implement right, left level order traversals and also implement a function which returns a pointer to the
root of a tree which is a mirror image of the given tree

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
    void preorder(node *n){
        if(n == nullptr){
            return ;
        }
        cout<<n->data<<" " ;
        preorder(n->left) ;
        preorder(n->right) ;
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

    vector<int> left_view_level_order(node *n){
        vector<int> result ;
        if(n == nullptr){
            return result ;
        }
        queue<node*> pq ; 
        reult.push_back(n->data) ;
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
// In order successor of a given node node with the min value of all the nodes whose keys are greater than the given key
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
    T.getdepth(n, 140, depth5 ; 
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