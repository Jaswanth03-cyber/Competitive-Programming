#include <bits/stdc++.h>
using namespace std ;


   /*
                front    rare
                <---     --->
   */

struct node{
    int data ;
    node *next ;
    node *prev ;
};

class Dequeue{
    private:
    node *front ;
    node *rare ;
    public :
    Dequeue(){
        this->front = nullptr ;
        this->rare = nullptr ;
    }

    void push_front(int a){
        node *temp = new node ;
        temp->data = a ;
        temp->next = nullptr ;
        temp->prev = nullptr ;

        if(rare == nullptr){
            front = temp ;
            rare = temp ;
        }
        else{
            temp->next = front ;
            front->prev = temp ;
            front = temp ;
        }
    }

    void push_back(int a){
        node* temp = new node ;
        temp->data = a ;
        temp->next = nullptr ;
        temp->prev = nullptr ;
        if(rare == nullptr){
            front = temp ;
            rare = temp ;
        }
        else{
            rare->next = temp ;
            temp->prev = rare ;
            rare = temp ;
        }
    }

    void pop_front(){
        if(front == nullptr){
            cout<<"Dequeue is empty "<<endl ;
            return ;
        }
        else if(front->next == nullptr){
            rare = nullptr ;
            front = nullptr ;
            return ;
        }
        node* temp = front ;
        front = front->next ;
        front->prev = nullptr ;
        delete temp ;
    }

    void pop_back(){
        if(rare == nullptr){
            cout<<"Dequeue is empty "<<endl ; // when no elements
            return ;
        }
        if(rare->prev == nullptr){ // when this is the last element 
            rare = nullptr ;
            front = nullptr ;
            return ;
        }
        node* temp = rare ;
        rare = rare->prev ;
        rare->next = nullptr ;
        delete temp ;
    }

    void print_front(){
        if(front == nullptr){
            cout<<"The dequeu is empty "<<endl ;
            return ;
        }
        node* temp = front ;
        while(temp != nullptr){
            cout<<temp->data<<" " ;
            temp = temp->next ;
        }
        cout<<endl ;
    }

    void print_back(){
        if(rare == nullptr){
            cout<<"The dequeue is empty "<<endl ;
            return ;
        }
        node* temp = rare ;
        while(temp != nullptr){
            cout<<temp->data<<" " ;
            temp = temp->prev ;
        }
        cout<<endl ;
    }

    int frontval(){
        return front->data ;
    }
    int backval(){
        return rare->data ;
    }

    bool checkrare(){
        return rare == nullptr ;
    }

    bool checkfront(){
        return front == nullptr ;
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    Dequeue dq ;
    dq.push_front(10) ;
    dq.push_front(9) ;
    dq.push_front(11) ;
    dq.push_front(12) ;

    dq.push_back(13) ;
    dq.push_back(14) ;
    dq.push_back(15) ;

    dq.print_front() ;
    dq.print_back() ;

    dq.pop_front() ;
    dq.pop_front() ;
    dq.pop_front() ;
    dq.pop_front() ;
    dq.pop_front() ;
    dq.pop_front() ;


    dq.pop_front() ;

    // cout<<dq.checkfront()<<endl ;
    // cout<<dq.checkrare()<<endl ;

    // cout<<dq.frontval()<<endl ;
    // cout<<dq.backval()<<endl ;

    dq.print_front() ;
    dq.print_back() ;
    return 0 ;
}