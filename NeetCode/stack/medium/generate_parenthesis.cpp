#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/generate-parentheses/description/
*/
/*
Logic is that there are 2*n places we have to fill these places with the brackets '(' and ')' such that final string is a balanced string 
so we maintain a count of number of open and number of closed brackets. so whenever open and closed are 0 we have got a valid string.
we can not have close < open as ')' can not start before '(' and also open and close can not be zero 
so first if we take '(' we process next all the possible parenthesis.

temp vector as a string  every call has two recursive calls I have represented only valid one I have also shown open and closed count
                                    ""   O-3, C-3
                            
                                    "(" O-2,C-3
                    
                "((" O-1,C-3                            "()" O-2,C-2

    "(((" 0,3             "(()" 1,2                       "()(" 1,2

    "((()" 0,2      "(()(" 0,2    "(())" 1,1        "()((" 0,2      "()()" 1,1

    "((())" 0,1     "(()()" 0,1   "(())(" 0,1       "()(()" 0,1     "()()(" 0,1

    "((()))" 0,0   "(()())" 0,0   "(())()" 0,0      "()(())" 0,0    "()()()" 0,0    

Number of valid parenthesis for given n 
catalan number 

2n
  C
   n

*/

class Solution {
public:
    void solve(vector<string> &ans, vector<char> &temp, int open, int close){
        if(open == 0 && close == 0){
            string valid(temp.begin(), temp.end()) ;
            ans.push_back(valid) ;
        }

        if(open > close || open < 0 || close < 0){
            return ;
        }

        temp.push_back('(') ;
        solve(ans, temp, open - 1, close) ;
        temp.pop_back() ;

        temp.push_back(')') ;
        solve(ans, temp, open, close - 1) ;
        temp.pop_back() ;
    }
    vector<string> generateParenthesis(int n) {
        int open = n, close = n ;
        vector<char> temp ;
        vector<string> ans ;
        solve(ans, temp, open, close) ;
        return ans ;
    }
};