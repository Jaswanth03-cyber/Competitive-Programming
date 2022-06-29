#include<iostream>
using namespace std ;
// defining node
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
// class BST
int change(int *b){
    *b = (*b)*(*b) ;
    return *b ;
}
class binarysearchtree{

    public:
    node *root ;
// constructor with root initialisation 
    binarysearchtree(int a){
        root = Newnode(a) ;
    }
// constructor with root as nullptr 
    binarysearchtree(){
        root = nullptr ;
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
        // but that return is used to eturn the node in the reccurssive calls 
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
// searching for a node with a given value 
    node* search(node* n, int a){
        if(n == nullptr){
            // cout<<"There are no nodes in the tree to search"<<endl ;
            return n ;
        }
        if(n->data == a){
            cout<<"The node with value "<<a<<" is found"<<endl ;
            return n ;
        }
        if(n->data > a){
            return search(n->left,a) ;
        }
        if(n->data < a){
            return search(n->right,a) ;
        }
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
    // If the key to be deleted is smaller than the root's key then it lies in left subtree
    if(n->data > a){
        n->left = Delete(n->left,a) ;
    }
    // If the key to be deleted is greater than the root's key, then it lies in right subtree
    else if(n->data < a){
        n->right = Delete(n->right,a) ;
    }
    // if key is same as root's key, then This is the node to be deleted
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
        // has both the children case 3 
        // here we try to get the in order sucessor of the node 
        node *temp = inorder_sucessor(n) ;
        // copying the data of inorder sucessor 
        // cout<<temp->data<<endl ;
        n->data = temp->data ;
        n->right = Delete(n->right, temp->data);
    }
    return n ;
}
};
int main(int argc, char **argv){
    binarysearchtree T(30) ;
    node *n = T.root ;
    //node *m = T.insert(n,45) ;
    int a = 3 ;
    int b = change(&a) ;
    cout<<b<<endl ;
    cout<<a<<endl ;
    node *m =  T.insert(n,35) ;
    T.insert(n,90) ;
    T.insert(n,27) ;
    T.insert(n,29) ;
    T.insert(n,1)  ;
    T.inorder(n) ;
    cout<<endl ;
    T.postorder(n) ;
    cout<<endl ;
    T.preorder(n) ;
    cout<<endl ;
    n = T.Delete(n,27) ;
    T.inorder(n) ;
    cout<<endl ;
    T.postorder(n) ;
    cout<<endl ;
    T.preorder(n) ;
    cout<<endl ;
    n = T.Delete(n,90) ;
    T.inorder(n) ;
    cout<<endl ;
    T.postorder(n) ;
    cout<<endl ;
    T.preorder(n) ;
    cout<<endl ;
    return 0 ;
}