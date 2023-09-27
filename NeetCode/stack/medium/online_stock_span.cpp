#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/online-stock-span/
*/
/*
if so the current price is less than the top one just span is 1 return it and push the current one to the stack
if in case it is greater than the top value then the span of the top value can be added to the current price and no need of that anymore
so popping it because this values span can come in the one we are adding just see the exxample given you will get an idea.
*/

class StockSpanner {
public:
    stack<pair<int, int>> st ;
    StockSpanner() {

    }
    
    int next(int price) {
        int span = 1 ;
        while(!st.empty() && st.top().first <= price){
            span = span + st.top().second ;
            st.pop() ;
        }
        st.push({price, span}) ;
        return span ;
    }
};