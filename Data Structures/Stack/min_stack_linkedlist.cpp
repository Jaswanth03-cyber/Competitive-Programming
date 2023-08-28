#include <bits/stdc++.h>
using namespace std ;


struct node{
    int data ;
    node* next ;
    int Minsofar;
};

class Stack{
    private :
    node* head ;
    public:
    Stack(){
        head = new node ;
        head = nullptr ;
    }

    void push(int a){
        node* temp = new node ;
        temp->data = a ;
        temp->next = head ;
        if(head == nullptr){
            temp->Minsofar = a ;
        }
        else{
            temp->Minsofar = min(head->Minsofar, a) ;
        }
        head = temp ;
    }

    int top(){
        return head->data ;
    }

    void pop(){
        if(head == nullptr){
            cout<<"There is an underflow "<<endl ;
        }
        node *temp = head ;
        head = temp->next ;
        delete temp ;
    }

    void print(){
        node *temp = head ;
        while(temp != nullptr){
            cout<<temp->data<<" " ;
            temp = temp->next ;
        }
        cout<<endl ;
    }

    void printmin(){
        node *temp = head ;
        while(temp != nullptr){
            cout<<temp->Minsofar<<" " ;
            temp = temp->next ;
        }
        cout<<endl ;
    }

    int getmin(){
        return this->head->Minsofar ;
    }

};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    Stack st ;
    st.push(2) ;
    st.push(4) ;
    st.push(5) ;
    st.push(3) ;
    st.push(6) ;
    st.push(1) ;

    cout<<st.getmin()<<endl ;
    st.print() ;
    st.printmin() ;
    st.pop() ;
    cout<<st.getmin()<<endl ;
    return 0 ;
}