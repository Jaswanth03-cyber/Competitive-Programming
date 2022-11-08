#include<bits/stdc++.h>
using namespace std ;

void swap(int &a, int &b){
    int temp = a ;
    a = b ;
    b = temp ;
    return ;
}

class Heap{
    public:
    int *keys ;
    int size ;
    int capacity ;
    Heap(int a){
        this->capacity = a ;
        keys = new int[this->capacity] ;
        this->size = 0 ;
        for(int i = 0 ; i < this->capacity-1 ; i++){
            keys[i] = -1 ;
        }
    }
    int parent(int a){
        return (a-1)/2 ;
    }
    int leftchild(int a){
        return (2*a + 1) ;
    }
    int rightchild(int a){
        return (2*a + 2) ;
    }
    int getmin(){
        return keys[0] ;
    }
    void insert(int element){
        if(this->size == capacity){
            cout<<"heap is full"<<endl ;
            return ;
        }
        this->keys[this->size] = element ;
        this->size++ ;
        int current = this->size - 1 ;
        while(current > 0 && (keys[current] < keys[parent(current)])){
            swap(keys[current], keys[parent(current)]) ;
            current = parent(current) ;
        }
        return ;
    }
    void heapify(int index){
        if(this->size <= 1){
            return ;
        }
        int left_index = leftchild(index) ;
        int right_index = rightchild(index) ;
        int smallest = index ;
        if( (keys[left_index] < keys[index])  && (left_index < this->size) ){
            smallest = left_index ;
        }
        if( (keys[right_index] < keys[smallest]) && (right_index < this->size) ){
            smallest = right_index ;
        }
        if(smallest != index){
            swap(keys[index], keys[smallest]) ;
            heapify(smallest) ;
        }
        return  ;
    }
    void Delete(int key){
        int m = 0 ;
        for(int i = 0 ; i < this->size ; i++){
            if(this->keys[i] == key){
                m = i ; 
                break ;
            }
        }
        if(m == this->size - 1){
            keys[m] = -1 ;
        }
        else{
            keys[m] = -1 ;
            swap(keys[m], keys[this->size-1]) ;
        }
        this->size-- ;
        for(int i = this->size/2 - 1 ; i >=0 ; i--){
            heapify(i) ;
        }
    }
    void print(){
        for(int i = 0 ; i < this->size ; i++){
            cout<<keys[i]<<" " ;
        }
        cout<<endl ;
    }
    ~Heap(){
        delete[] keys ;
    }
};
int main(){
    Heap H(18) ;
    H.insert(20) ;
    H.insert(30) ;
    H.insert(17) ;
    H.insert(14) ;
    H.insert(21) ;
    H.insert(44) ;
    H.insert(10) ;
    H.insert(6) ;
    H.print() ;
    for(int i = 1 ; i < 7;i++){
        H.heapify(i) ;
    }
    // H.print() ;
    H.Delete(6) ;
    H.print() ;
    return 0 ;
}