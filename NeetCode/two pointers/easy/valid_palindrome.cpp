#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/valid-palindrome/description/
*/

/*
So if we can see the constraints we need to do the sum in O(N) or else O(LogN) as O(N) is not working we have to check it in O(LogN)

So now we are having two pointers l = 0 and r = n-1 now, if both are alphanumeric checking if they are same and incrementing l and decreasing r
but, now if one of them is not alphanumeric we should not change that l or r which is not alphanumeric as we have to ignore non alphanumeric
characters, and remember we can not change a character in a string thats why I have created two character variables one and two after
checking which value is not alphanumeric processing that 
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length() ;
        int l = 0 ;
        int r = n-1 ;
        bool ans = true ;
        char temp = 32 ;
        char one = 'a' ;
        char two = 'b' ;
        while(l <= r){
            if(isalnum(s[l]) && isalnum(s[r])){
                one = s[l] ;
                two = s[r] ;
                if(s[l] >= 'A' && s[l] <= 'Z'){
                    one = s[l] + 32 ;
                }
                if(s[r] >= 'A' && s[r] <= 'Z'){
                    two = s[r] + 32 ;
                }
                if(one != two){
                    ans = false ;
                    break ;
                }
                l++ ;
                r-- ;
            }
            else{
                if(isalnum(s[l])){
                    if(!isalnum(s[r])){
                        r-- ;
                    }
                }
                else{
                    if(!isalnum(s[r])){
                        l++ ;
                        r-- ;
                    }
                    else{
                        l++ ;
                    }
                }
                continue ;
            }
        }
        return ans ;
    }
};


int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    string ans = "abc" ;
    ans = ans + 'i' ;

    cout<<ans<<endl ;

    return 0 ;
}