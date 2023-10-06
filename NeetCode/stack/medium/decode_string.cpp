#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/decode-string/description/
*/

/*
When ever we encounter a ']' what we do is that we have a currsubstring which contains the final answer there may be nested ones
like 2b[[2a3[c]]] so thats why we maintain currsubstring and a stack of substrings and freq whenever we encounter opening bracket we got a pair of 
substring and a multiplier that need to be repeated so push into the respective stacks and reset the curr values to empty values so if it is a digit
just adding it to the multiplier if it is some character add it to the currsusbstring.

run the below code for the example 2b[[2a3[c]]] you will get an idea 
*/
class Solution {
public:
    string decodeString(string s) {
        int n = s.length() ;
        stack<int> freq ;
        stack<string> substrings ;
        int factor = 0 ;
        string currsubstring = "" ;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == ']'){
                string temp = substrings.top() ;
                substrings.pop() ;
                int count = freq.top() ;
                freq.pop() ;
                for(int i = 0 ; i < count ; i++){
                    temp = temp + currsubstring ;
                }
                currsubstring = temp ;
            }
            else if(s[i] == '['){
                freq.push(factor) ;
                substrings.push(currsubstring) ;
                factor = 0 ;
                currsubstring = "" ;
            }
            else if(isdigit(s[i])){
                factor = factor*10 + s[i] - '0' ;
            }
            else{
                currsubstring = currsubstring + s[i] ;
            }
        }
        return currsubstring ; 
    }
};