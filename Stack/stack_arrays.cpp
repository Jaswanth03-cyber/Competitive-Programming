#include<iostream>
using namespace std ;
class stack{
    private:
    int card ;
    int *elements ;
    int cap ;
    public:
    stack(int a){
        card = 0 ;
        elements = new int[a] ;
        cap = a ;
    }
    void insert(int a){
        if(card >= a){
            cout<<"there is no place in the stack"<<endl ;
        }
        else{
            elements[card] = a ;
            card++ ;
        }
    }
    int top(){
        return elements[this->card -1] ;
    }
    void delete_last(){
        if(card == 0){
            cout<<"There are no elements in the stack"<<endl ;
        }
        else{
            card-- ;
        }
    }
    bool isempty(){
        return card==0 ;
    }
    bool isfull(){
        return card== cap ;
    }
    void print(){
        if(isempty()){
            return ;
        }
        for(int i =0; i<card;i++){
            cout<<elements[i]<<" " ;
        }
        cout<<endl ;
    }
    int size(){
        return this->card ;
    }
    ~stack(){
        delete[] elements ;
    }
};
int main(){
    stack s(100) ;
    s.insert(3) ;
    s.insert(6) ;
    s.insert(9) ;
    s.delete_last() ;
    cout<<s.size()<<endl ;
    s.print() ;
    cout<<s.top()<<endl  ;
    return 0 ;
}