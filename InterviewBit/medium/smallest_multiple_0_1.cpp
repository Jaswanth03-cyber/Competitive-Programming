#include <bits/stdc++.h>
using namespace std ;

/*
https://www.interviewbit.com/problems/smallest-multiple-with-0-and-1/
*/
string Solution::multiple(int A) {
    if(A == 1){
        return "1" ;
    }
    queue<int> pq ;
    pq.push(1) ;
    vector<int> parent(A, -1) ;
    vector<int> steps(A, -1) ;
    
    while(!pq.empty()){
        int top = pq.front() ;
        pq.pop() ;
        if(top == 0){
            break ;
        }
        for(int i = 0 ; i < 2 ; i++){
            int curr = (top*10 + i)%A ;
            if(parent[curr] == -1){
                parent[curr] = top ;
                steps[curr] = i ;
                pq.push(curr) ;
            }
        }
    }
    string ans = "" ;
    for(int i = 0 ; i != 1 ; i = parent[i]){
        ans = ans + to_string(steps[i]) ;
    }
    ans = ans + to_string(1) ;
    reverse(ans.begin(), ans.end()) ;
    return ans ; 
}

/*
we are having N states here N states are nothing but the 0 to N-1 where N is the given number A these N states represent the reminder when a number 
is divided by N so our problem is to find the minimum path from the node 1 to node 0 we start at node 1 and our edges correspond to which number
we add either 1/0 so steps retrace which number is added either 0/1 and parent retraces from which node we came to this node 

so we start with 1 so for all numbers with only zeros possible building from 1 is that multiply with 10 everytime add 1/0 so 
just take the reminder and if that reminder is not visited yet push into the queue whenever 0 occurs thats the smallest number 
note a reminder can occur many times as here path from node 1 to node 0 is cyclic but we want smallest number so we are pushing nodes into the
queue only when they are visited first time as we want smallest number whenever we revisit them it is probably when we are having a number greater 
than that when previously visited that.
*/