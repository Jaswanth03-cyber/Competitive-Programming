#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/implement-stack-using-queues/description/
*/

class MyStack {
public:
    queue<int> pq1 ;
    queue<int> pq2 ; 
    MyStack() {
        //
    }
    
    void push(int x) {
        pq1.push(x) ; 
    }
    
    int pop() {
        while(pq1.size() > 1){
            pq2.push(pq1.front()) ;
            pq1.pop() ;
        }
        int top = pq1.front() ;
        pq1.pop() ;
        // pq2.push(top) ;
        swap(pq1, pq2) ;
        return top ;
    }
    
    int top() {
        while(pq1.size() > 1){
            pq2.push(pq1.front()) ;
            pq1.pop() ;
        }
        int top = pq1.front() ;
        pq1.pop() ;
        pq2.push(top) ;
        swap(pq1, pq2) ;
        return top ;
    }
    
    bool empty() {
        return (pq1.empty() && pq2.empty());  
    }
};