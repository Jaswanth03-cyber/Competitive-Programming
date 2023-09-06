#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/valid-palindrome-ii/description/
*/

/*
Logic that I have used is that I have considered two cases
if s[l] != s[r] then we can have two cases either remove l or remove r so in first loop I have considered removing l
if again somewhere we require deleting in the sense it is not possible to make a palindrome

similarly I have taken a case where I have removed r and also checked the remaining string if so again we need to delete we can not make
the given string palindrome if any one of them is true then we can make a palindrome.
*/

class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.length() ;
        int l = 0 ;
        int r = n - 1 ;
        int count1 = 0 ;
        int count2 = 0 ;
        bool ans1 = true ;
        bool ans2 = true ;
        bool ans = true ;
        while(l <= r){
            if(s[l] == s[r]){
                l++ ; 
                r-- ;
                continue ;
            }
            else{
                if(s[l+1] == s[r]){
                    l++ ;
                    count1++ ;
                }
                else{
                    ans1 = false ;
                    break ;
                }
            }
        } 
        l = 0 ;
        r = n -1 ;
        while(l <= r){
            if(s[l] == s[r]){
                l++ ; 
                r-- ;
                continue ;
            }
            else{
                if(s[r-1] == s[l]){
                    r-- ;
                    count2++ ;
                }
                else{
                    ans2 = false ;
                    break ;
                }
            }
        } 
        if(count1 > 1){
            ans1 = false ;
        } 
        if(count2 > 1){
            ans2 = false ;
        }
        if(!ans1 && !ans2){
            ans = false ;
        }
        return ans ;
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    string s = "" ;
    cin>>s ;
    Solution ans ;
    bool res = ans.validPalindrome(s) ;
    cout<<res<<endl ;
    return 0 ;
}