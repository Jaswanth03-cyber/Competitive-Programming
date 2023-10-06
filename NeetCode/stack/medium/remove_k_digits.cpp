#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/remove-k-digits/
*/

/*
so like if we just observe the numbers we push the numbers if we encounter a minimum we are removing the elements from the top and
decreasing the number of changes if still k is left then we remove the elements see here we are removing the elements from back side
because we are having all the elements in the stack in an increasing order until then if k still is not 0
so if we remove from back number obtained will be less 

for example lets say 

1112233 and k is given as 4 then as while loop wont execute we will end up 1112233 in the stack its in increasing order as k is not still 0
so we remove last k digits 

1432219 for this even before the complete string is processed k will be zero so we can not change, so after for loop as k == 0 we will end up with the final result
note in the stack is in reverse direction be careful.
*/
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st ;
        st.push(num[0]) ;
        for(int i = 1 ; i < num.length() ; i++){
            while(!st.empty() && k > 0 && st.top() > num[i]){ // here its not >= as we will get a wrong answer for 112 and k = 1 we will end up with 12 rather than 11
                st.pop() ;
                k-- ;
            }
            st.push(num[i]) ;
        }
        while(k--){
            st.pop() ;
        }

        string ans = "" ;
        while(!st.empty()){
           ans = st.top() + ans ;
           st.pop() ;
        }
        while(ans[0] == '0'){
           ans.erase(0, 1) ;
        }
        if(ans== ""){
            return "0" ;
        }
        return ans ;
    }
};