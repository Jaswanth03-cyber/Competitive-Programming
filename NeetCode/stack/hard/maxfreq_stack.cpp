#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/maximum-frequency-stack/description/
*/

class FreqStack {
public:
    int maxfreq ;
    map<int, int> freq ;
    map<int, stack<int>> stacks ;
    FreqStack() {
        maxfreq = 0 ; 
    }
    
    void push(int val) {
        int currfreq ;
        if(freq.find(val) == freq.end()){
            freq.insert({val, 0}) ;
        }
        freq[val]++ ;
        currfreq = freq[val] ;
        if(currfreq > maxfreq){
            maxfreq = currfreq ;
            stack<int> st ;
            stacks.insert({maxfreq, st}) ;
        }
        stacks[currfreq].push(val) ;
    }
    int pop() {
        int res = stacks[maxfreq].top() ;
        freq[res]-- ;
        stacks[maxfreq].pop() ;
        if(stacks[maxfreq].empty()){
            maxfreq = maxfreq - 1 ;
        } 
        return res ;
    }
};

/*
basically what we are doing is that we are having a freq map which has the count of the elements and also I am having a map of 
stacks where all the elements with that freq are present in the stack 

so just run for an example given you will get an idea 
so if we are adding a value which is already present then we will increment the freq now update the maxfreq if maxfreq is being updated we 
need a new stack for that freq if not no need of new stack we will directly append to the old stack we are mapping to a stack instead of other
data structure because to pop the recent one as given in the question 

when popping the most freq element do not forget to decrease the count and also we popped out the most freq element if in case 
most freq stack is empty we need to decrease the maxfreqeunce if not there are elements with the maxfreq 

for given ex  5 7 5 7 4 5 

freq :-
4 -> 1 
5 -> 3 
7 -> 2

1 -> [5,7,4]
2-> [5, 7]
3-> [5] now you can get an idea what is being done just grouping the elements in an order and also grouped based on the freq
*/