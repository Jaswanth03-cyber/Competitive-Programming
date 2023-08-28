#include <bits/stdc++.h>
using namespace std ;

// one stack has order same as normal queue, one has elements as normal stack itself just take some eample you will get an idea
class Queue{
    private:
    stack<int> st1 ; // one for pushing 
    stack<int> st2 ; // one for poping 
    public:

    Queue(){
        //
    }

    void push(int val){
        st1.push(val) ;
    }

    void pop(){
        if(this->empty()){
            cout<<"The Queue is empty "<<endl ;
            return ;
        }

        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top()) ;
                st1.pop() ;
            }
        }

        st2.pop() ;
    }

    int front(){
        if(this->empty()){
            cout<<"The Queue is empty "<<endl ;
            return ;
        }

        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top()) ;
                st1.pop() ;
            }
        }

        return st2.top() ;
    }

    bool empty(){
        return st1.empty() && st2.empty() ;
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    return 0 ;
}