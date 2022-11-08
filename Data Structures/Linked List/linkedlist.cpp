#include<iostream>
using namespace std ;
// here data can be int/ double for all we use templates so that no need to repeat for many data types 
struct node{
    int data ;
    node *next ;
};
class linkedlist{
    private:
    int card ;
    node *head ;
    public:
    linkedlist(){
        this->card = 0 ;
        head = nullptr ;
    }
    void insert(int a){
        node *n = new node ;
        n->data = a ;
        n->next = head ;
        head = n ;
        card++ ;
        return ;
    }
    node *search(int a){
        node *n = head ;
        while(n != nullptr){
            if(n->data == a){
                return n ;
            }
            n = n->next ;
        }
        return nullptr ;
    }
    void delete_by_node(node *p){
        node *n = this->head ;
        bool found = false ;
        while(n != nullptr){
            if(n->next == p){
                n->next = p->next ;
                delete p ;
                found = true ;
                card-- ;
            }
            if(found){
                cout<<"deleted the given node"<<endl ;
                return ;
            }
            n = n->next ;
        }
        if(!found){
            cout<<"there is no such node"<<endl ;
        }
        return ;
    }
    void print(){
        node *n = this->head ;
        while(n != nullptr){
            cout<<n->data<<" " ;
            n = n->next ;
        }
        cout<<endl ;
        return ;
    }
    int size(){
        return this->card ;
    }
    ~linkedlist(){
        node *n = this->head, *current = nullptr; //initialization part
        while(n){
            current = n;
            n=n->next;
            delete current;
        }
    }

};
int main(){
    linkedlist l ;
    l.insert(9) ;
    l.insert(3) ;
    l.insert(6) ;
    cout<<l.size()<<endl ;
    node *n = new node ;
    node *m = new node ;
    m->data = 10 ;
    //int a ;
    //cin>>a ;
    //n = l.search(a) ;
    //if(n == nullptr){
        //cout<<"there is no node whose value is "<<a<<endl ;
    //}
    //else{
      //  cout<<"value found "<<n->data<<endl ;
    //}
    l.delete_by_node(m) ;
    l.print() ;
    node *y = l.search(3) ;
    l.delete_by_node(y) ;
    l.print() ;
    return 0 ;
}