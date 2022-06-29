#include<iostream>
using namespace std ;
struct node{
    int data ;
    node *next ;
};
class queue{
    private:
    int size ;
    node *front ;
    node *rare ;
    public:
    queue(){
        size = 0 ;
        front = nullptr ;
        rare = nullptr ;
    }
    void enqueue(int a){
        this->size++ ;
        node *n = new node ;
        n->data = a ;
        if(rare == nullptr){
            front = n ;
            rare = n ;
            return ;
        }
        else{
            rare->next = n ;
            rare = n ;
        }
        return ;
    }
    int dequeu(){
        if(isempty()){
            return -1 ;
        }
        this->size-- ;
        node *a = this->front ;
        int value = a->data  ;
        front = front->next;
        delete a ;
        if(this->size == 0){
            rare = nullptr ;
        }
        return value ; 
    }
    bool isempty(){
        return this->size == 0 ;
    }
    int cardinality(){
        return this->size ;
    }
    void print(){
        if(isempty()){
            cout<<"there are no elements to print"<<endl ;
        }
        else{
            for(node *n = this->front ; n != nullptr ; n = n->next ){
                cout<<n->data<<" " ;
            }
            cout<<endl ;
        }
        return ;
    }
    ~queue(){
        node *n = this->front, *current = nullptr; 
        while(n){
            current = n;
            n=n->next;
            delete(current);
        }
    }
};
int main(){
    queue  q ;
    int m = q.dequeu() ;
    if(m < 0){
        cout<<"The queue is empty"<<endl ;
    }
    else{
        cout<<m<<endl ;
    }
    q.enqueue(3) ;
    q.enqueue(6) ;
    q.enqueue(9) ;
    int a = q.cardinality() ;
    cout<<a<<endl ;
    q.enqueue(5) ;
    q.enqueue(8) ;
    q.enqueue(7) ;
    int z = q.dequeu() ;
    if(z < 0){
        cout<<"The queue is empty"<<endl ;
    }
    else{
        cout<<z<<endl ;
    }
    int n = q.dequeu() ;
    if(n < 0){
        cout<<"The queue is empty"<<endl ;
    }
    else{
        cout<<n<<endl ;
    }
    q.enqueue(21) ;
    q.print() ;
    return 0 ;
}
