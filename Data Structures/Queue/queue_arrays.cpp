#include<bits/stdc++.h>
using namespace std ;
class queue{
    private:
    int front ;
    int rare ;
    int *elements ;
    int size ;
    int capacity ;
    public:
    queue(int a){
        capacity = a ;
        front =  0;
        rare = capacity - 1  ;
        elements = new int[a] ;
        size = 0 ;
    }
    void enqueue(int a){
        if(isfull()){
            cout<<"The queue is full"<<endl ;
            return ;
        }
        this->rare = (this->rare + 1)%(this->capacity) ;
        elements[this->rare] = a ;
        this->size++ ;
        return ;
    }
    int dequeue(){
        if(size == 0){
            return -1 ;
        }
        int a = elements[this->front] ;
        this->front = (this->front + 1)%capacity ;
        this->size-- ;
        return a ;
    }
    bool isempty(){
        if(this->size == 0){
            return true ;
        }
        return false ;
    }
    bool isfull(){
        if(this->size == capacity){
            return true ;
        }
        return false ;
    }
    void print(){
        for(int i = this->front ; i <= this->rare ; i++){
            cout<<this->elements[i]<<" " ;
        }
        cout<<endl ;
        return ;
    }
    int size_queue(){
        return this->size ;
    }
    ~queue(){
        delete[] elements ;
    }
};
int main(){

    ios_base::sync_with_stdio(0) ;
    cin.tie(NULL) ;
    
    queue q(100) ;
    q.enqueue(3) ;
    q.enqueue(6) ;
    q.enqueue(9) ;
    int a = q.size_queue() ;
    q.enqueue(8) ;
    q.enqueue(10) ;
    int z = q.dequeue() ;
    q.enqueue(21) ;
    cout<<z<<endl ;
    cout<<q.size_queue()<<endl ;
    q.print() ;
    return 0 ;
}