#include<iostream>
using namespace std ;
struct node{
    int data ;
    node *next ;
};
class stack{
    private:
    int cap ; // actually no need of capacity as it is dynamic number can be as large as possible can not be fixed like in array implementaion 
    int card ;
    node *head ;
    public:
    stack(int a){
        cap = a ;
        card = 0 ;
        head = nullptr ;
    }
    void push(int a){
        if(card>= cap){
            cout<<"There is no space"<<endl ;
            return ;
        }
        else{
            node *n = new node ;
            n->data = a ;
            n->next = head ;
            head = n ;
            card++ ;
        }
        return ;
    }
    int pop(){
        node *n = this->head ;
        int value = n->data ;
        this->head = head->next ;
        delete n ;
        cout<<head->data<<endl ;
        card-- ;
        return value ;
    }
    void print(){
        node *n = head ;
        while(n != nullptr){
            cout<<n->data<<" " ;
            n = n->next ;
        }
        cout<<endl ;
        return ; 
    }
    ~stack(){
        node *n = this->head, *current = NULL; //initialization part
        while(n){
            current = n;
            n=n->next;
            delete(current);
        }
    }
};
int main(){
    stack S(100) ;
    S.push(3) ;
    S.push(6) ;
    S.push(9) ;
    S.push(16) ;
    S.push(7) ;
    int a = S.pop() ;
    S.push(8) ;
    S.push(5) ;
    // cout<<a<<endl ;
    S.print() ;
}