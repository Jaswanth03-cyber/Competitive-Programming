#include<iostream>
using namespace std ;
struct node{
    int data ;
    node *next ;
};
class hashtable{
    private:
    int size ;
    int *keys ;
    int hash_function(int key){
        int index ;
        index = (key)%(this->size) ;
        return index ;
    }
    node **head ;
    int *link_size ;
    public:
    hashtable(int cap){
        this->size = cap ;
        keys = new int[cap] ;
        head = new node*[cap] ;
        link_size = new int[cap] ;
        for(int i = 0; i < cap; i++){
            keys[i] = -1 ;
            head[i] = nullptr ;
            link_size[i] = 0 ;
        }
    }
    void insert(int key){
        int index = hash_function(key) ;
        if(keys[index] == -1){
            keys[index] = key ;
            cout<<"inserted the key "<<key<<" in the array at index "<<index<<endl ; 
        }
        else if(keys[index] == 0){
            keys[index] = key ;
            cout<<"inserted the key "<<key<<" at index "<<index<<endl ;            
        }
        else{
            link_size[index]++ ;
            node *n = new node ;
            n->data = key ;
            n->next = head[index] ;
            head[index] = n ;
            cout<<"inserted the key "<<key<<" in the linked list present at index "<<index<<" at node "<<link_size[index]<<endl ;
        }
        return ;
    }
    void delete_key(int key){
        int index = hash_function(key) ;
        bool found = false ;
        if(keys[index] == key){
            keys[index] = 0 ;              // taking X to be 0 tombstone ;
            found = true ;
            if(found){
                cout<<"delete the key in the array at index "<<index<<endl ;
            }
            return ;
        }
        else{
            node *n = new node ;
            n =  head[index] ;
            while(n != nullptr){
                if(n->next == nullptr){
                    if(n->data == key){
                        head[index] = nullptr ;
                        delete n ;
                        link_size[index]-- ;
                        found = true ;
                    }
                    if(found){
                        cout<<"Deleted the key present at the last node in the linked list present at index "<<index<<endl ;
                    }
                    return ;
                }
                if((n->next)->data == key){
                    if(n->next->next == nullptr){
                        n->next = nullptr ;
                        delete n->next ;
                        break ;
                        found = true ;
                        link_size[index]-- ;
                    }
                    n->next = (n->next)->next ;
                    delete n->next ;
                    link_size[index]-- ;
                    found = true ;
                    break  ;
                }
                n = n->next ;
            }
            if(found){
                cout<<"deleted the key "<<key<<" from the node in the linked list at index "<<index<<endl ;
            }
        }
        if(!found){
            cout<<"There is no such key in the table to delete "<<endl ;
        }
        return ;
    }
    bool search(int key){
        int index = hash_function(key) ;
        if(keys[index] == key){
            cout<<key<<" key is found in the array itself at index "<<index<<endl ;
            return true ;
        }
        else{
            node *n = new node ;
            n = head[index] ;
            while(n != nullptr){
                if(n->data == key){
                    cout<<key<<" key is in the linked list present at the index "<<index<<endl ;
                    break ;
                }
                n = n->next ;
            }
            return true ;
        }
        cout<<key<<" key is not in the hash table "<<endl ;
        return false ;
    }
    void print(int a){
        int index = a%(this->size) ;
        if(keys[index] == -1 || keys[index] == 0){
            cout<<"there is no key in the array "<<endl ;
        }
        node *n = head[index] ;
        if(n == nullptr){
            cout<<"There are no values in the linked list at the index "<<index<<endl ;
        }
        else{
            cout<<"Values in the linked list at index "<<index<<" are : " ;
            while(n != nullptr){
                cout<<n->data<<" " ;
                n = n->next ;
            }
            cout<<endl ;
        }
    }
    ~hashtable(){
        delete[] keys ;
    }
};
int main(){
    hashtable H(100);
    H.insert(90) ;
    H.insert(190) ;
    H.insert(100) ;
    H.insert(3) ;
    H.insert(33) ;
    H.insert(103) ;
    H.insert(203) ;
    H.insert(303) ;
    H.insert(403) ;
    bool f = H.search(103) ;
    H.delete_key(103) ;
    bool g = H.search(203) ;
    H.print(3) ;
    return 0 ;
}