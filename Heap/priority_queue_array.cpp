#include<iostream>
using namespace std ;
struct data{
    int key ;
    int priority ;
};
class priority_queue{
    private:
    data* items ;
    int size ;
    int capacity ;
    public:
    priority_queue(int a){
        this->size = 0 ;
        this->capacity = a ;
        items = new data[a] ;
    } 
    void enqueue(int a, int b){ 
        if(this->size == capacity){
            cout<<"the queue is full"<<endl ;
            return ;
        }
        items[this->size].key = a ;
        items[this->size].priority = b ;
        this->size++ ;
        return ;
    }
    int peek(){
        int current = 0 ;
        for(int i = 0 ; i < this->size ; i++){
            if(items[current].priority < items[i].priority){
                current = i  ;
            }
            else if(items[current].priority == items[i].priority){
                if(items[current].key < items[i].key){
                    current = i ;
                }
                else{
                    continue ;
                }
            }
            else{
                continue ;
            }
        }
        return current ;    // returns the index number where highest priority is 
    }
    void deqeue(){
        if(this->size == 0){
            cout<<"There are no elements to remove"<<endl ;
            return ;
        }
        int index = peek() ;
        for(int i = index ; i < this->size ; i++){
            items[i] = items[i+1] ;
        }
        this->size-- ;
        return ;
    }
    void print(){
        for(int i = 0 ; i < this->size ; i++){
            cout<<"The key present in this node is : "<<items[i].key<<" and its priority is : "<<items[i].priority<<endl ;
        }
    }
    ~priority_queue(){
        delete[] items ;
    }
};
int main(){
    priority_queue q(30) ;
    q.enqueue(3,1) ;
    q.enqueue(6,2) ;
    q.enqueue(9,3) ;
    q.enqueue(12,4) ;
    q.enqueue(15,10) ;
    q.enqueue(18,6) ;
    q.enqueue(21,7) ;
    q.enqueue(24,8) ;
    q.enqueue(27,9) ;
    q.print() ;
    int b = q.peek() ;
    cout<<b<<endl ;
    q.deqeue() ;
    q.print() ;
    q.enqueue(30,10) ;
    int a = q.peek() ;
    cout<<a<<endl ;
    return 0 ;
}