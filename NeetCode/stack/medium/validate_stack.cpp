#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/validate-stack-sequences/description/
*/

/*
Logic :-

I have taken i =0, j = 0 and also had an empty stack, if the stack is not empty I have checked whether the top element of the stack is same as
popped[j] so now I have popped that element, now after this pop event I can even have a pop event or push event it depends on the next element in 
the popped array if the next popped element is same as current stack top we need to pop again no push should be done so thats whenever st.top() == popped[j]
we just pop that element and increment the j we are not sure about next can be pop or push, if in next iteration popped[j] is not same as st.top() so we need to
push the ith element if so st.top() is same as popped[j] pop the element and continue after all the elements are pushed, if the remaining elements 
in the stack or in the order of popped elements from where we are left then given sequences are not valid 

ex 
[1,2,3,4,5] [4,5,3,2,1]
so push until 1,2,3,4  now st.top() == popped[0] so I have popped it and incremented j but did not push 5 as we are not sure about next operation
now st.top() != popped[1] so it means push operation must be done so 5 is pushed as all the elements are pushed now remaining elements must be popped

[1,2,0] [2,1,0]
So in this 1 is pused and 2 is pushed now as the st.top() is same as popped[0] we pop it and increment j 
now again as st.top() is same as popped[1] we pop it 
next stack is empty have to push an element so pushed 0 which can be the popped element so its true 

so above example shows why we have written continue in the while 

Note after the while loop stack will not be empty at all as atleats last element of the pushed array will be in the stack as no pop operations after it
*/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        bool ans = true ;
        stack<int> st ;
        int i = 0 ;
        int j = 0 ;
        int n = pushed.size() ;
        while(i < n){
            if(!st.empty()){
                if(st.top() == popped[j]){
                    st.pop() ;
                    j++ ;
                    continue ; 
                }
            }
            st.push(pushed[i]) ;
            i++ ;
        }
        for(int k = j ; k < n ; k++){
            if(st.top() != popped[k]){
                ans = false ;
                break ;
            }
            st.pop() ;
        }
        return ans ; 
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    cin>>n ;
    vector<int> pushed(n, 0) ;
    vector<int> popped(n, 0) ;
    for(int i =0 ; i < n ; i++){
        cin>>pushed[i] ;
    }
    for(int i = 0 ; i < n ; i++){
        cin>>popped[i] ;
    }

    Solution ans;
    int res = ans.validateStackSequences(pushed, popped) ;
    cout<<res<<endl ;
    return 0 ;
}