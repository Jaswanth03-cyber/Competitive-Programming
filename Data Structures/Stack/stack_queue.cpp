#include <bits/stdc++.h>
using namespace std ;

// #include <iostream>
// #include <queue>

// using namespace std;

// class StackUsingQueue {
// private:
//     queue<int> q;

// public:
//     void push(int item) {
//         q.push(item);

//         // Rearrange the queue to simulate stack behavior
//         int size = q.size();
//         for (int i = 0; i < size - 1; ++i) {
//             q.push(q.front());
//             q.pop();
//         }
//     }

//     int pop() {
//         if (q.empty())
//             return -1; // Stack is empty

//         int top_element = q.front();
//         q.pop();
//         return top_element;
//     }

//     int top() {
//         if (q.empty())
//             return -1; // Stack is empty

//         return q.front();
//     }

//     bool empty() {
//         return q.empty();
//     }
// };

// int main() {
//     StackUsingQueue stack;

//     stack.push(1);
//     stack.push(2);
//     stack.push(3);

//     cout << stack.pop() << endl; // Output: 3
//     cout << stack.top() << endl; // Output: 2

//     stack.push(4);

//     cout << stack.pop() << endl; // Output: 4
//     cout << stack.pop() << endl; // Output: 2
//     cout << stack.pop() << endl; // Output: 1
//     cout << stack.pop() << endl; // Output: -1 (empty)

//     return 0;
// }

class Stack{
    private:
    queue<int> pq1 ;
    queue<int> pq2 ;

    public:
    Stack(){
        //
    }

    void push(int val){
        pq1.push(val) ;
    }

    void pop(){
        if(pq1.size() == 0){
            cout<<"Stack is empty "<<endl ;
            return ;
        }

        while(pq1.size() > 1){
            pq2.push(pq1.front()) ;
            pq1.pop() ;
        }

        //removing the last element that has been added 
        pq1.pop() ;
        swap(pq1, pq2) ;
    }

    int top(){
        if(pq1.size() == 0){
            cout<<"Stack is empty "<<endl ;
            return -1 ;
        }

        while(pq1.size() > 1){
            pq2.push(pq1.front()) ;
            pq1.pop() ;
        }

        //returning the last element that has been added 
        int ans = pq1.front() ;
        pq2.push(pq1.front()) ;
        pq1.pop() ;
        swap(pq1, pq2) ;  
        return ans ;     
    }

    bool empty(){
        return pq1.empty() && pq2.empty() ;
    }

    void display(){
        if(pq1.size() == 0){
            cout<<"There are no elements to display "<<endl ;
        }

        while(pq1.size() > 0){
            cout<<pq1.front()<<" " ;
            pq2.push(pq1.front()) ;
            pq1.pop() ;
        }
        cout<<endl ;
        swap(pq1, pq2) ;
    }

};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    Stack st ;
    st.push(9) ;
    st.push(8) ;
    st.push(6) ;
    st.push(7) ;

    st.display() ;
    st.pop() ;
    cout<<st.top()<<endl ;
    st.display() ;
    return 0 ;
}